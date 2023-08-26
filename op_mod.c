#include "monty.h"

/**
 * _mod - Computes the rest of division of the second top element by the top element.
 * @stack: Double pointer to the beginign of the stack.
 * @line_number: Line number being processed.
 *
 * Return: None.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
