#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the stack data structure
 * @line_number: line number of opcode swap command
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
