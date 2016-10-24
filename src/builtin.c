#include "stdafx.h"

internal_command builtins[] = {
        BUILTIN_DEF(jsh_exit, "exit"),
        BUILTIN_DEF(ext_exec, "call"),
        BUILTIN_DEF(jsh_version, "ver"),
	{0, 0, 0}
};

int jsh_exit(int argc, char **argv)
{
	status.quit = true;
	return 1;
}

int jsh_version(int argc, char **argv)
{
	fprintf(status.f_out, "version\n");
	return 1;
}

// this is executed if a line is empty
int empty_input_wrapper(int argc, char **argv)
{
	fputc('\n', status.f_out);
	return 1;
}
