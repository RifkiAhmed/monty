#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack data structure
 * @line_number: line number of opcode pop command
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

}
