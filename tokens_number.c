#include "monty.h"

/**
 * tokens_number - counts number of words in @str
 * @str: pointer to string
 *
 * Return: number of tokens
 */
unsigned int tokens_number(char *str)
{
	unsigned int count = 0;

	while (*str)
	{
		while (isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (!isspace(*str) && *str);

		++count;
	}
	return (count);
}

