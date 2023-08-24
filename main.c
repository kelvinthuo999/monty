#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/* Global variables */
FILE *monty_file;
stack_t *stack = NULL;
char *line = NULL;
unsigned int line_number = 0;

int main(int argc, char *argv[])
{
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, line_number, strtok(NULL, " \t\n"));
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(stack);
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(stack, line_number);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(&stack, line_number);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(&stack, line_number);
			}
			else if (strcmp(opcode, "add") == 0)
			{
				add(&stack, line_number);
			}
			else if (strcmp(opcode, "nop") == 0)
			{
				/* Do nothing for nop opcode */
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
