#include "shell.h"

/**
 *_Str_len - A func that calculate the length.
 *@s: first arg
 *Return: the length.
 */
size_t	_Str_len(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
