#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * push - Adds an element onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number being processed.
 * @value: Value to be pushed onto the stack.
 *
 * Return: None.
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	/* Allocate memory for the new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	UNUSED(line_number);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
