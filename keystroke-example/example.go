package main

import (
	"github.com/superp00t/etc/yo"

	"github.com/superp00t/keystroke"
)

func main() {
	p := keystroke.New()

	p.On("Alt+Shift+Z", func() {
		yo.Ok("Activated")
	})

	p.On("N+J+K", func() {
		yo.Puke(p)
	})

	yo.Spew(p)

	p.Run()
}
