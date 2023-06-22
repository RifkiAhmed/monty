#include "monty.h"

/**
 * tokenize - breaks @str into a sequence of zero or more nonempty tokens
 * @lineptr: pointer to string to tokenize
 *
 * Return: array of strings
 */
char **tokenize(char *lineptr)
{
	char **tokens = NULL;
	unsigned int count = 0;

	if (!lineptr)
		return (NULL);

	count = tokens_number(lineptr);
	if (count == 0)
		return (NULL);

	count++;
	tokens = malloc(sizeof(char *) * count);
	if (tokens == NULL)
		return (NULL);

	for (count = 0; *lineptr; ++count)
	{
		while (isspace(*lineptr))
			*lineptr++ = '\0';
		if (*lineptr)
			tokens[count] = lineptr;
		else
			break;
		do {
			++lineptr;
		} while (*lineptr && !isspace(*lineptr));
	}
	tokens[count] = NULL;

	return (tokens);
}
