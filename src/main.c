#include "stdafx.h"

shared_config config;

int main(int argc, char **argv)
{
	// load config;
	initialize_config(&config);
	// process_args;
	jsh_repl(stdin);
	return EXIT_SUCCESS;
}

void initialize_config(shared_config *c)
{
	c->f_in = stdin;
	c->f_out = stdout;
	c->f_err = stderr;
	c->shuttingdown = false;
	c->last_return_value = 0;
}

void jsh_repl(FILE *input, bool quiet)
{
	// REPL loop;
	do {
		if (!quiet) printf(DEFAULT_PS1);
		char *line = freadline(stdin);
		if (!line)
		{
			config.shuttingdown = true;
			continue;
		}
		// fprintf(stderr, "Get line: %s\n", line);
	    char **token = tokenize_line(line);

		exec(token);

		free(token);
		free(line);

		// check return status;
		// fprintf(stderr, "Return value: %d\n", config.last_return_value);

	} while(!config.shuttingdown);
}
