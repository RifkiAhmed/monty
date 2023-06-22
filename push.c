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

	if (var.argv[1] == NULL || is_digit(var.argv[1]) == -1)
	{
		free_stack(*stack);
		invalid_instr("L%u: usage: push integer\n", line_number);
	}

	ele = malloc(sizeof(stack_t));
	if (ele == NULL)
	{
		free_stack(*stack);
		invalid_instr("Error: malloc failed\n");
	}
	ele->n = atoi(var.argv[1]);
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
