#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack data structure
 * @line_number: line number of opcode command
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
