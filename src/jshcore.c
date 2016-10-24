#include "stdafx.h"

char *freadline(FILE *src)
{
	char *read_buffer = NULL;
	size_t buffer_size = 0;
	size_t buffer_index = 0;
	char current_char;
	bool buffer_end = false;
	while (!buffer_end)
	{
		// expend buffer size
		if (buffer_index >= buffer_size)
		{
			char *rbak = read_buffer;
			read_buffer = realloc(read_buffer, buffer_size += READ_BUF_SIZE * sizeof(char));
			if (!read_buffer)
			{
				fprintf(stderr, "Cannot allocate memory\n");
				free(rbak);
				return NULL;
			}
		}
		// read a char
		current_char = fgetc(src);
		// if reached file end
		if (current_char == EOF && buffer_index == 0)
		{
			free(read_buffer);
			return NULL;
		}
		// if reached line end then fill buffer end 0 and return
		if (current_char == EOF || current_char == '\n')
		{
			current_char = 0;
			buffer_end = true;
		}
		read_buffer[buffer_index++] = current_char;
	}

	return read_buffer;
}

char **tokenize_line(char *line)
{
	// if got a empty line
	if (!strlen(line))
	{
		return NULL;
	}
	char **tok_buf = NULL;
	size_t tok_buf_size = 0;
	size_t tok_buf_index = 0;
	char *current_token = NULL;
	current_token = strtok(line, TOKEN_DELIMETERS);
	while (current_token)
	{
		if (tok_buf_index >= tok_buf_size)
		{
			char **tbak = tok_buf;
			tok_buf = realloc(tok_buf, tok_buf_size += TOKEN_SPLIT_BUF_SIZE);
			if (!tok_buf)
			{
				free(tbak);
				fprintf(stderr, "Cannot allocate memory");
				return NULL;
			}
		}
		tok_buf[tok_buf_index++] = current_token;
		current_token = strtok(NULL, TOKEN_DELIMETERS);
	}
	tok_buf[tok_buf_index] = current_token;
	return tok_buf;
}

int exec(char **tokens)
{
	// check if it is a builtin function, if true, execute it
	if (int_exec(0, tokens)) {}
	// check if it is an external program, if true, execute it
	else if (ext_exec(0, tokens)) {}
	else fprintf(stderr, "Not an internal or external command\n");
	return 0;
}