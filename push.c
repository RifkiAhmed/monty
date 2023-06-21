#include "monty.h"
#include <stdio.h>
/**
 * push - push an element to the stack
 * @stack: pointer to the stack
 * @line_number: integer line number of opcode
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *ele;

	ele = malloc(sizeof(stack_t));

	if (ele == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	if (var.data == NULL || is_digit(var.data) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	ele->n = atoi(var.data);
	ele->prev = NULL;
	if (*stack == NULL)
	{
		ele->next = NULL;
		*stack = ele;
	}
	else
	{
		ele->next = *stack;
		*stack = ele;
	}
}
