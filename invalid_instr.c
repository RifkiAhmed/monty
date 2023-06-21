#include "monty.h"

/**
 * invalid_instr - prints error msg if line contains an invalid instruction
 * @msg: format for message
 *
 * Return: Nothing
 */
void invalid_instr(char *msg, ...)
{
	va_list va_arg;

	va_start(va_arg, msg);
	vfprintf(stderr, msg, va_arg);
	va_end(va_arg);
	exit(EXIT_FAILURE);
}
