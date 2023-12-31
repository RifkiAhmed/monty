#include "monty.h"

/**
 * op_execute - find function related to given opcode command
 * and execute it if it founds
 * @opcode: string of opcode command
 * @stack: stack data structure type
 * @line_number: line number of opcode command
 */
void op_execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t command[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}, {"sub", sub}, {"div", op_div}, {"mul", mul},
		{"mod", mod},
		{"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr},
		{NULL, NULL}
	};

	if (strcmp(opcode, "stack") == 0)
	{
		var.mode = 1;
		return;
	}
	if (strcmp(opcode, "queue") == 0)
	{
		var.mode = -1;
		return;
	}
	i = 0;
	while (command[i].opcode)
	{
		if (strcmp(opcode, command[i].opcode) == 0)
		{
			(command[i].f)(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", var.line_number, opcode);
	free_stack(*stack);
	free(var.lineptr);
	exit(EXIT_FAILURE);
}
