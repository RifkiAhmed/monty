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

	if (var.data == NULL || is_digit(var.data) == -1)
	{
		free_stack(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(var.lineptr);
		exit(EXIT_FAILURE);
	}

	ele = malloc(sizeof(stack_t));
	if (ele == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		free(var.lineptr);
		exit(EXIT_FAILURE);
	}
	ele->n = atoi(var.data);
	if (*stack == NULL)
	{
		ele->next = NULL;
		ele->prev = NULL;
		*stack = ele;
	}
	switch (var.mode)
	{
	case 1:
		lifo(stack, ele);
		break;
	case -1:
		fifo(stack, ele);
		break;
	default:
		lifo(stack, ele);
	}
}
