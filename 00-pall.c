#include "monty.h"

/**
 * pall - prints all element in the stack
 * @stack: pointer to the stack data structure
 * @line_number: line number of opcode pall command
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
