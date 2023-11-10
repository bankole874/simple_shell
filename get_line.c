#include "shell.h"
/**
 * _All - Read from fd.
 * @fd: first argument.
 * @left: second argument.
 * Return: string
 */

static char *_All(int fd, char *left)
{
	char *buffer;
	int readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readed && !my_strchr(left, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		left = my_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

/**
 * the_get_line - extract one line.
 * @line: first argument.
 * Return: string
 */

static char *the_get_line(char *line)
{
	int i;
	char *ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line, i);
	if (line[i] == '\n')
	{
		ptr[i] = '\n';
		ptr[i + 1] = '\0';
	}
	else
		ptr[i] = '\0';
	return (ptr);
}

/**
 * _ft_left - extracts the left part of the string.
 * @line: first argument.
 * Return: string
 */

static char *_ft_left(char *line)
{
	int i;
	char *ptr;

	i = 0;
	if (!line)
		return (NULL);
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ptr = malloc(my_strlen(line) - i + 1);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line + i + 1, my_strlen(line) - i);
	ptr[my_strlen(line) - i] = '\0';
	return (ptr);
}

/**
 * _get_line - read a line from file description.
 * @fd: first argument.
 * @global: second argument.
 * Return: string, NULL.
 */

char *_get_line(int fd, global_t *global)
{
	static char *left;
	char *line;
	char *next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = all(fd, left);
	next_line = get_line(line);
	left = ft_left(line);
	global->left = left;
	free(line);
	return (next_line);
}

