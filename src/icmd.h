#pragma once
#ifndef __ICMD_H__
#define __ICMD_H__

typedef int(*command_func)(int argc, char **argv);

typedef struct icmd {
	command_func function;
	size_t length;
	char *command;
} internal_command;

#define BUILTIN_DEF(FUNC, CMD) { FUNC, sizeof(CMD), CMD }

#endif
