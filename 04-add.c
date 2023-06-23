#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of opcode add command
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
