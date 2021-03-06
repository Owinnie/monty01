#include "monty.h"
#include <stdio.h>
/**
 * processor - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 **/
int processor(char *filename, stack_t **stack)
{
	size_t len = 0;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp = NULL;
	char *op;


	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while (getline(&line, &len, fp) != -1)
	{
		op = strtok(line, DELIMS);
		line_number++;
		if (op)
			eval_op(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
