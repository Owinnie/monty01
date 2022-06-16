#include "monty.h"

/**
 * a_dd - adds top 2 nodes of the stack
 * @stack: double pointer to top of stack
 * @line_number: value of node
 **/
void a_dd(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	p_op(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * n_op - do anything
 * @stack: double pointer to top of stack
 * @line_number: value of node
 **/
void n_op(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * s_ub - substracts top node from second top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 **/
void s_ub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	p_op(stack, line_number);
	(*stack)->n -= tmp;
}

/**
 * d_iv - divides second node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 **/
void d_iv(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	if (tmp == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	p_op(stack, line_number);
	(*stack)->n /= tmp;
}

/**
 * m_ul - multiplies second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void m_ul(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	p_op(stack, line_number);
	(*stack)->n *= tmp;
}
