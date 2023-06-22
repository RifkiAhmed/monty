#include "monty.h"

/**
 * is_digit - checks if argument given is of type integer
 * @s: pointer to string
 *
 * Return: 0 if @s is integer or -1 if not
 */
int is_digit(char *s)
{
	if (s == NULL || *s == '\0')
		return (-1);
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	return (0);
}
