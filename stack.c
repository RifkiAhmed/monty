#include "monty.h"

/**
 * lifo - push an element to the stack
 * @stack: pointer to the stack
 * @ele: element to add
 *
 * Return: Nothing
 */
void lifo(stack_t **stack, stack_t *ele)
{
	ele->next = *stack;
	(*stack)->prev = ele;
	*stack = ele;
}
