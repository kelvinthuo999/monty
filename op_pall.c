#include "monty.h"

/**
 * pall - Prints all elements in the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Unused parameter */

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
