#include "monty.h"
/**
 * open_file - opens a file
 * @file_name: the file namepath
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		error(2, file_name);
	}
	read_file(fd);
	fclose(fd);
}
/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 */
void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}
/**
 * parse_line - separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format
 * Return: 0 if the opcode is stack. 1 if queue
 */
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	find_func(opcode, value, line_number, format);
	return (format);
}
