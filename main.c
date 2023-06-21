#include "monty.h"
#include <stdio.h>
#include <string.h>
var_t var = {0, NULL};
/**
 * main - checks code
 * @argc: number of args
 * @argv: args vector
 *
 * Return: 0 if success or EXIT_FAILURE if it fails
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[256];
	char *opcode;
	stack_t *stack;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	var.line_no = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		var.line_no++;
		var.data = NULL;
		opcode = strtok(line, " \n\0");
		var.data = strtok(NULL, " \n\0");
		get_opcode(opcode)(&stack, var.line_no);
	}
	fclose(file);

	return (0);
}
