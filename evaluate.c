#include "monty.h"

/**
 * eval_op - decide which function to call
 * @stack: double pointer to head of stack data structure
 * @op: operator
 * @line_number: line in byte-code file being processed
 * Return: int
 **/
void eval_op(stack_t **stack, char *op, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", p_ush},
		{"pall", p_all},
		{"pint", p_int},
		{"pop", p_op},
		{"swap", s_wap},
		{"add", a_dd},
		{"nop", n_op},
		{"sub", s_ub},
		{"div", d_iv},
		{"mul", m_ul},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_number, op);
		exit(EXIT_FAILURE);
	}
}
