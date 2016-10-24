#include "stdafx.h"

internal_command builtins[] = {
        BUILTIN_DEF(jsh_exit, "exit"),
        BUILTIN_DEF(ext_exec, "call"),
        BUILTIN_DEF(jsh_about, "about"),
        {0, 0, 0}
};

int jsh_exit(int argc, char **argv)
{
	// printf("quitting...\n");
	config.shuttingdown = true;
	return 0;
}

int jsh_about(int argc, char **argv)
{
	fprintf(config.f_out,
		SHELL_NAME
		" Version " STR(VERSION_MAJOR) "." STR(VERSION_MINOR) "." STR(VERSION_REVISION) "\n"
		SHELL_DESCRIPTION "\n"
		);
	return 0;
}

// this is executed if a line is empty
int empty_input_wrapper(int argc, char **argv)
{
	fputc('\n', config.f_out);
	return 0;
}
