#include "monty.h"
/**
 * p_int - prints value at top of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void p_int(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
