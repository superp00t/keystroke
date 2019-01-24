# keystroke

keystroke aims to be a simple, cross-platform Cgo library for specifying global key combination bindings.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Requirements

- C Compiler
- Linux/FreeBSD/Dragonfly only: x11 development headers

# TODO

- Test on Windows ✓
- Test on Linux ❌ 
- Test on Mac OS ❌

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
    os.Exit()
  })

  err := k.Run()
  if err != nil {
    fmt.Println(err)
  }
}
```