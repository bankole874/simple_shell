#include "shell.h"

/**
 *_Str_comp - This function compares two strings.
 *@s1: first arg
 *@s2: sec arg
 *@n: third arg
 *Return: 0 if equal.
 */
int	_Str_comp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
