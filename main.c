#include "monty.h"
#include <stdio.h>

var_t var = {NULL, NULL, NULL, 0, 0, NULL};
/**
 * main - checks code
 * @argc: number of args
 * @argv: args vector
 *
 * Return: 0 if success or EXIT_FAILURE if it fails
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		invalid_instr("USAGE: monty file\n");

	if (!freopen(argv[1], "r", stdin))
		invalid_instr("Error: Can't open file %s\n", argv[1]);

	while (getline(&var.lineptr, &var.n, stdin) > 0)
	{
		var.line_number++;
		var.argv = tokenize(var.lineptr);

		if (var.argv)
			get_opcode(*var.argv)(&var.stack, var.line_number);
		free(var.argv);
		var.argv = NULL;
		free(var.lineptr);
		var.lineptr = NULL;
	}
	return (0);
}
