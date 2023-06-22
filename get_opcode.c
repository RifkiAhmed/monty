#include "monty.h"
#include <string.h>
/**
 * get_opcode - find function related to given spcifier
 * @s: format specifier
 *
 * Return: function pointer or NULL if not found
 */
void (*get_opcode(char *s))()
{
	int i;
	instruction_t name[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	i = 0;
	if (s)
	{
		while (name[i].opcode)
		{
			if (strcmp(s, name[i].opcode) == 0)
			{
				return (name[i].f);
			}
			i++;
		}
		invalid_instr("L%u: unknown instruction %s\n", var.line_number, s);
	}
	return (NULL);
}
