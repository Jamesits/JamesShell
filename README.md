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
 * [x] Builtin commands:
    + [x] `exit`
    + [x] `cd`
    + [x] `about`
 * [x] Execution of external executables
 * [x] `/etc/jshrc`, `./.jsh_profile`, `./.jshrc` are executed on launch
 * [ ] Environment variables support
 * [ ] POSIX style expansion (tilde, etc.)
 * [ ] Pipe
 * [ ] Scripting
 * [ ] Colored terminal support

# About

Written by [James Swineson](https://swineson.me).
Heavily impressed by [Tutorial - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/).
