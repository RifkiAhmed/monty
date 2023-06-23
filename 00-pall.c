#include "monty.h"
/**
 * pall - push an element to the stack
 * @stack: pointer to the stack
 * @line_number: integer line number of opcode
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ele;

	(void)line_number;
	if (*stack == NULL)
		return;
	ele = *stack;
	while (ele)
	{
		printf("%d\n", ele->n);
		ele = ele->next;
	}
}
