package core

// #cgo !darwin, !windows LDFLAGS: -lX11 
// #cgo darwin CFLAGS: -framework ApplicationServices
// #include "kstroke.h"
import "C"

import (
	"errors"
)

type Event struct {
	Arg   uintptr
	Key   uint8
	State bool
}

var _handler func(Event) int

func Listen(cb func(Event) int) error {
	_handler = cb

	errCode := C.callback_kstroke_listen(C.uintptr_t(0))
	errC := int(errCode)
	
	switch errC {
		case 0:
		return nil

		case -1:
		return errors.New("kstroke/core: could not open X11 display")

		case -2:
		return errors.New("kstroke/core: failed to create event tap; you need to enable \"Enable access for assistive devices\" in the Universal Access preference panel")
	}

	panic(errC)
}

//export callGoPointer
func callGoPointer(ptr C.uintptr_t, key C.uint8_t, state C.bool) C.int {
	return C.int(_handler(Event{uintptr(ptr), uint8(key), bool(state)}))
}
