#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number of opcode rotl command
 *
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
}
