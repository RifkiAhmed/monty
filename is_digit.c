#include "monty.h"

/**
 * is_digit - checks if argument given is of type integer
 * @s: pointer to string
 *
 * Return: 0 if @s is integer or -1 if not
 */
int is_digit(char *s)
{
	int ii;

	if (s == NULL)
		return (-1);
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}
