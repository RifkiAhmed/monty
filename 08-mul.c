#include "monty.h"

/**
 * mul -  multiplies the second top element of the stack with the top one
 * @stack: pointer to the stack
 * @line_number: line number of opcode mul command
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
