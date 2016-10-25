# JamesShell

A simple and naive UNIX shell.

## Features

 * [x] Up and running
 * [x] No memory leakage
 * [ ] CMake
 * OS coverage
    + [x] Linux
    + [ ] macOS (partial, debugging is hard since Valgrind is not supported)
    + [ ] Linux Subsystem for Windows
    + [ ] Native Windows
    + [ ] Lagecy UNIX
    + [ ] Plan9
 * Builtin commands
    + [x] `exit`
    + [ ] `cd` (partial, no tilde expansion and must be followed by a path)
    + [x] `about`
 * [x] Execution of external executables
 * [ ] rc files support (partial, no tilde expansion so put them under pwd)
    + `/etc/jshrc`
    + `./.jsh_profile`
    + `./.jshrc`
 * [ ] Environment variables support
 * [ ] Comment support (ignore `#`)
 * [ ] POSIX style expansion (tilde, etc.)
 * [ ] Pipe
 * [x] Scripting: invoke as `jsh script1 [script2 [script3 ...]]`
 * [ ] Colored terminal support
 * [ ] Arguments

# About

Written by [James Swineson](https://swineson.me).
Heavily impressed by [Tutorial - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/).
