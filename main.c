#include "monty.h"
#include <stdio.h>
#include <string.h>
var_t var = {NULL, 0, NULL};
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
	char line[1024];
	char *opcode;

	if (argc != 2)
		invalid_instr("USAGE: monty file\n");
	file = fopen(argv[1], "r");
	if (file == NULL)
		invalid_instr("Error: Can't open file %s\n", argv[1]);
	var.line_no = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		var.line_no++;
		var.data = NULL;
		opcode = strtok(line, " \n\0");
		var.data = strtok(NULL, " \n\0");
		get_opcode(opcode)(&var.stack, var.line_no);
	}
	fclose(file);
	return (0);
}
