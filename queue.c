#include "monty.h"

/**
 * fifo - push an element to the stack "FIFO mode"
 * @stack: pointer to the stack
 * @ele: element to add
 *
 * Return: Nothing
 */
void fifo(stack_t **stack, stack_t *ele)
{
	stack_t *temp;

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = ele;
	ele->prev = temp;
	ele->next = NULL;
}
