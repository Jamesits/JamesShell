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
		
		// for (int i = 0; token[i]; ++i) fprintf(stderr, "Token #%d: %s\n", i, token[i]);
		fprintf(stderr, "Before exec: quit = %d\n", config.shuttingdown);
		exec(token);
		fprintf(stderr, "After exec: quit = %d\n", config.shuttingdown);

		free(token);
		free(line);
	} while(!config.shuttingdown) ;
	// check return status;
	
	return EXIT_SUCCESS;
}
