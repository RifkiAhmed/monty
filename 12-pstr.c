#include "monty.h"

/**
 * pstr - prints the strings starting at the top of the stack
 * @stack: pointer to the stack data structure
 * @line_number: line number of opcode pstr command
 *
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	temp = *stack;
	while (temp)
	{
		if (temp->n == 0)
		{
			putchar('\n');
			return;
		}
		if (temp->n >= 0 && temp->n <= 127)
		{
			putchar(temp->n);
		}
		else
		{
			putchar('\n');
			return;
		}
		temp = temp->next;
	}
	putchar('\n');
}
