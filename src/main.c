#include "stdafx.h"

shared_config status;

void initialize_status(shared_config *s)
{
	s->f_in = stdin;
	s->f_out = stdout;
	s->f_err = stderr;
	s->quit = false;
	s->last_return_value = 0;
}

int main(int argc, char **argv)
{
	// load config;
	initialize_status(&status);
	// process_args;
	// enter REPL loop;
	while(!status.quit)
	{
		printf(DEFAULT_SHELL_PROMPT);
		char *line = freadline(stdin);

		printf("Get line: %s\n", line);

	      	char **token = tokenize_line(line);
		exec(token);
		free(line);
		free(token);
	}
	// check return status;
	
	return EXIT_SUCCESS;
}
