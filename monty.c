#include "monty.h"
glob_t glob;
/**
 * main - monty bytecode interpreter
 * @argc: no. of args
 * @argv: array of strs containing args
 * Return: EXIT_SUCCESS or EXIT_FAILURE!!!
 **/
int main(int argc, char **argv)
{
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	processor(argv[1], &head);
	exit(EXIT_SUCCESS);
}
/**
 * stack_init - initialize
 * @head: top of stack data structure
 **/
void stack_init(stack_t **head)
{
	*head = NULL;
	glob.top = head;
}
/**
 * free_all - free all malloc'ed memory
 *     note: this is available "atexit", starting at
 *           getline loop
 **/
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(glob.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
/**
 * processor - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
 **/
int processor(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
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
	while ((read = getline(&line, &len, fp)) != -1)
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
