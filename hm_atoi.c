#include "shell.h"

/**
 * _theatoi - converts a str to an int.
 * @s: arg 1.
 * Return: int.
 */
int _theatoi(char *s)
{
	unsigned int	n;
	int				sign;
	int				i;

	n = 0;
	i = 0;
	sign = 0;
	while (s[i] && (s[i] == '+' || s[i] == '-' || s[i] == ' ' || s[i] == '\t'))
	{
		if (s[i] == '-')
			sign++;
		i++;
	}
	while (s[i] && (s[i] < '0' || s[i] > '9'))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	if (sign % 2 == 0)
		return (n);
	return (-n);
}
