# keystroke

keystroke aims to be a simple, cross-platform Cgo library for specifying global key combination bindings.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Requirements

- C Compiler
- on Mac OS: run process as root, or whitelist app in Privacy settings
- Linux/FreeBSD/Dragonfly only: x11 development headers

# TODO

- Tested on Windows ✓
- Tested on Mac OS ✓
- Test on Linux ❌ 

# Example

```go
package main

import (
  "fmt"
  "os"

  "github.com/superp00t/keystroke"
)

func main() {
  k := keystroke.New()

  k.On("Alt+Shift+Z", func() {
    fmt.Println("Key combination invoked!")
  })

  k.On("N+J+K", func() {
    fmt.Println("Exiting")
    os.Exit(0)
  })

  err := k.Run()
  if err != nil {
    fmt.Println(err)
  }
}
```