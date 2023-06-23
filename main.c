#include "monty.h"

var_t var;
/**
 * main - executes code
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0, or "EXIT_FAILURE" if it fails
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t n = 0;
	char *opcode;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&var.lineptr, &n, file) != -1)
	{
		var.line_number++;
		opcode = strtok(var.lineptr, " \n");
		var.data = strtok(NULL, " \n");
		if (opcode != NULL && strcmp(opcode, "nop") != 0 && *opcode != '#')
			op_execute(opcode, &stack, var.line_number);
	}
	fclose(file);
	free(var.lineptr);
	free_stack(stack);
	return (0);
}
