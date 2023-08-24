#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * mul_op - Multiplies the second top element with the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
