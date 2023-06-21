#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct var_s - arguments
 * @ele: element to add or remove from stack
 * @line_no: opcode number of line
 * @data: integer
 *
 * Description: global variable
 */
typedef struct var_s
{
	stack_t *ele;
	unsigned int line_no;
	char *data;
} var_t;
extern var_t var;
int is_digit(char *s);
void (*get_opcode(char *s))();
void invalid_instr(char *msg, ...);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
#endif
