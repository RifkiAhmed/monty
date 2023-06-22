#include "monty.h"

var_t var;
/**
 * main - checks code
 * @argc: number of args
 * @argv: args vector
 *
 * Return: 0 if success or EXIT_FAILURE if it fails
 */
int main(int argc, char **argv)
{
	size_t n = 0;
	FILE *file;
	char *opcode;

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
		if (opcode != NULL)
			get_opcode(opcode, &var.stack, var.line_number);
	}
	fclose(file);
	free(var.lineptr);
	free_stack(var.stack);
	return (0);
}
