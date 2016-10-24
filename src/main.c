#include "stdafx.h"

shared_config config;

void initialize_config(shared_config *s)
{
	s->f_in = stdin;
	s->f_out = stdout;
	s->f_err = stderr;
	s->shuttingdown = false;
	s->last_return_value = 0;
}

int main(int argc, char **argv)
{
	// load config;
	initialize_config(&config);
	// process_args;
	// enter REPL loop;
	do {
		printf(DEFAULT_SHELL_PROMPT);
		char *line = freadline(stdin);

		// fprintf(stderr, "Get line: %s\n", line);
	    char **token = tokenize_line(line);

		exec(token);

		free(token);
		free(line);

		// check return status;
		fprintf(stderr, "Return value: %d\n", config.last_return_value);

	} while(!config.shuttingdown) ;
	
	return EXIT_SUCCESS;
}
