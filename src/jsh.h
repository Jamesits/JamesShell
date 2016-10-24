#pragma once
#ifndef __JSH_H__
#define __JSH_H__

#define SHELL_NAME "Jsh"
#define SHELL_DESCRIPTION "A simple and naive shell implementation by James Swineson."

#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REVISION 1

#define DEFAULT_SHELL_PROMPT "Jsh> "

#define READ_BUF_SIZE 1024
#define TOKEN_SPLIT_BUF_SIZE 16
#define TOKEN_DELIMETERS " \t\r\n"

#define SIZEOFARRAY(array) (sizeof(array) / sizeof(array[0]))

typedef struct shared_config {
	FILE *f_in;
	FILE *f_out;
	FILE *f_err;
	bool quit;
	int last_return_value;
} shared_config;

extern shared_config status;

char *freadline(FILE *src);
char **tokenize_line(char *line);
int exec(char **tokens);

#endif
