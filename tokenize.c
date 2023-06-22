#include "monty.h"

/**
 * tokenize - breaks @str into a sequence of zero or more nonempty tokens
 * @lineptr: pointer to string to tokenize
 *
 * Return: array of strings
 */
char **tokenize(char *lineptr)
{
	char **tokens = NULL, *token;
	unsigned int count = 0, i = 0;

	if (!lineptr)
		return (NULL);

	count = tokens_number(lineptr);
	if (count == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (++count));
	if (tokens == NULL)
		return (NULL);

	token = strtok(lineptr, " \t\n");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
