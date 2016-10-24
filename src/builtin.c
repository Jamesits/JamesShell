#include "stdafx.h"

internal_command builtins[] = {
        BUILTIN_DEF(jsh_cd, "cd"),
        BUILTIN_DEF(jsh_exit, "exit"),
        BUILTIN_DEF(ext_exec, "call"),
        BUILTIN_DEF(jsh_about, "about"),
        {0, 0, 0}
};

int jsh_cd(int argc, char **argv)
{
    if (argc == 0)
    {
        fprintf(config.f_err, "cd: Tilde expension not implemented");
    }
    else {
        if (chdir(argv[1]) != 0) {
            perror("cd");
        }
    }
    return 0;
}

int jsh_exit(int argc, char **argv)
{
	config.shuttingdown = true;
	return 0;
}

int jsh_about(int argc, char **argv)
{
	fprintf(config.f_out,
		SHELL_NAME " (" SHELL_SHORT_NAME ")\n"
		"Version " STR(VERSION_MAJOR) "." STR(VERSION_MINOR) "." STR(VERSION_REVISION) "\n\n"
		SHELL_DESCRIPTION "\n"
        SHELL_URL "\n\n"
		);
	return 0;
}

// this is executed if a line is empty
int empty_input_wrapper(int argc, char **argv)
{
	return 0;
}
