#pragma once
#ifndef __JSH_H__
#define __JSH_H__

typedef struct shared_config {
	FILE *f_in;
	FILE *f_out;
	FILE *f_err;
	bool shuttingdown;
	int last_return_value;
} shared_config;

char *freadline(FILE *src);
char **tokenize_line(char *line);
int exec(char **tokens);

#endif
