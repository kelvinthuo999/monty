#include "monty.h"

/**
 * swap - Interchanges the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being processed.
 *
 * Return: None.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	/* variable declaration */
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
