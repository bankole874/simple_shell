#include "shell.h"

/**
 * _my_memcpy - A func that copy memory area.
 * @dst: arg 1.
 * @src: arg 2.
 * @n: arg 3.
 * Return: The Pointer.
 */
void	*_my_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dst);
}

/**
 * _my_str_len - It calculate the length.
 * @s: arg 1.
 * Return: The length.
 */
size_t	_my_str_len(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

/**
 * _my_str_conc - It join two strings
 * @s1: arg 1.
 * @s2: arg 2.
 * Return: The pointer to the concatenated string.
 */
char	*_my_str_conc(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s2)
		return (0);
	ls2 = _my_str_len(s2);
	if (!s1)
		ls1 = 0;
	else
		ls1 = _my_str_len(s1);
	ptr = malloc(ls1 + ls2 + 1);
	if (!ptr)
		return (0);
	if (!s1)
		_my_memcpy(ptr, s2, ls2);
	else
	{
		_my_memcpy(ptr, s1, ls1);
		_my_memcpy(ptr + ls1, s2, ls2);
	}
	ptr[ls1 + ls2] = '\0';
	free(s1);
	return (ptr);
}

/**
 * _my_str_chrc - A func that locate first occurrence of a character.
 * @s: arg 1.
 * @c: arg 2.
 * Return: The pointer or NULL.
 */
char	*_my_str_chrc(const char *s, int c)
{
	char	*n;

	n = (char *)s;
	if (!s)
		return (NULL);
	while (*n)
	{
		if (*n == (char) c)
			return (n);
		n++;
	}
	if (*n == (char) c)
		return (n);
	return (NULL);
}
