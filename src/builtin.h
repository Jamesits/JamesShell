#pragma once
#ifndef __BUILTINS_H__
#define __BUILTINS_H__

int jsh_exit(int argc, char **argv);
int jsh_about(int argc, char **argv);
int int_exec(int argc, char **argv);
int ext_exec(int argc, char **argv);
int empty_input_wrapper(int argc, char **argv);

extern internal_command builtins[];

#endif
