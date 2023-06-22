#include "monty.h"

/**
 * get_opcode - find function related to given spcifier
 * @s: format specifier
 *
 * Return: function pointer or NULL if not found
 */
void get_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	i = 0;
	while (command[i].opcode)
	{
		if (strcmp(opcode, command[i].opcode) == 0)
		{
			command[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", var.line_number, opcode);
	free_stack(*stack);
	free(var.lineptr);
	exit(EXIT_FAILURE);
}
