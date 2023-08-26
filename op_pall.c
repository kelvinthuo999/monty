#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * pall - Prints the whole stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being processed.
 *
 * Return: None.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	UNUSED(line_number);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
