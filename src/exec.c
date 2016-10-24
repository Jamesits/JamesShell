#include "stdafx.h"

int int_exec(int argc, char **argv)
{
	if (argv == NULL)
	{
		empty_input_wrapper(argc, argv);
		return 0;
	}
	if (!argc)
		while (argv[argc++]);
	for (int i = 0; builtins[i].length; ++i)
		if (!strcmp(argv[0], builtins[i].command))
		{
			(builtins[i].function)(argc, argv);
			return 1;
		}
	return 0;
}

int ext_exec(int argc, char **argv)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0) 
	{
		// Child process
		if (execvp(argv[0], argv) == -1) 
		{
			perror("jsh cannot execvp");
		}
		else if (pid < 0)
		{
			// Error forking
			perror("jsh cannot fork");
		}
	}
	else
	{
		// Parent process
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

