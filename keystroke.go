package keystroke

import (
	"fmt"
	"strings"
	"sync"

	"github.com/superp00t/etc/yo"
	"github.com/superp00t/keystroke/core"
)

type combo struct {
	keys     []Key
	callback func()
}

type Processor struct {
	table   []*combo
	t       *sync.Mutex
	pressed []Key
}

func New() *Processor {
	p := new(Processor)
	p.table = []*combo{}
	p.t = new(sync.Mutex)

	return p
}

func (p *Processor) interested(pkey Key) bool {
	p.t.Lock()
	defer p.t.Unlock()

	for _, v := range p.table {
		for _, k := range v.keys {
			if k == pkey {
				return true
			}
		}
	}

	return false
}

func (p *Processor) On(keyCombo string, fn func()) error {
	keys, err := parseCombo(keyCombo)
	if err != nil {
		return err
	}
	p.t.Lock()
	p.table = append(p.table, &combo{
		keys,
		fn,
	})
	p.t.Unlock()

	return nil
}

func (p *Processor) Clear() {
	p.t.Lock()
	defer p.t.Unlock()
	p.table = []*combo{}
}

func parseCombo(str string) ([]Key, error) {
	els := strings.Split(str, "+")

	keys := []Key{}

	for _, v := range els {
		value, ok := Lookup[v]
		if !ok {
			return nil, fmt.Errorf("kstroke: %s is not a valid key name", v)
		}

		keys = append(keys, value)
	}

	return keys, nil
}

func keyeq(x, y []Key) bool {
	if len(x) != len(y) {
		return false
	}

	for i, v := range x {
		if v != y[i] {
			return false
		}
	}
	return true
}

func (p *Processor) matchAndDispatch() {
	p.t.Lock()
	defer p.t.Unlock()

	for _, v := range p.table {
		if keyeq(p.pressed, v.keys) {
			p.pressed = []Key{}
			go v.callback()
			return
		}
	}
}

func (p *Processor) event(ev core.Event) int {
	isint := p.interested(Key(ev.Key))
	yo.Warn("interested in", Key(ev.Key), isint)
	if !isint {
		return 0
	}

	if ev.State == true {
		p.pressed = append(p.pressed, Key(ev.Key))
		p.matchAndDispatch()
	} else {
		for _, v := range p.pressed {
			if v == Key(ev.Key) {
				p.pressed = []Key{}
				return 0
			}
		}
	}

	return 0
}

func (p *Processor) Run() error {
	return core.Listen(p.event)
}
