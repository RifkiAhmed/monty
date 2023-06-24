#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number of opcode rotr command
 *
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
