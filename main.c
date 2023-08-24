#include "monty.h"

/**
 * main - Entry point for the Monty interpreter program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char line[1024];
	char *opcode;
	int value;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (0);
}
