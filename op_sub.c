#include "monty.h"

/**
 * sub - Subtracts the first element of the stack from the second element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being processed.
 *
 * Return: None.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
