#include "monty.h"

/**
 * op_div - divides the second top element of the stack by the top one
 * @stack: pointer to the stack
 * @line_number: line number of opcode div command
 *
 * Return: Nothing
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
