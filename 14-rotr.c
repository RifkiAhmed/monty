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
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	temp->next->next = NULL;
	(*stack)->prev = NULL;	
}
