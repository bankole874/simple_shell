#include "shell.h"
/**
 * _All - It reads from fd.
 * @fd: first arg
 * @left: sec arg
 * Return: the string
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
 * the_get_line - It extract one line.
 * @line: first arg
 * Return: The extracted line
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
 * _ft_left - A function that extract the remaining part of the str.
 * @line: first arg
 * Return: The remaining part of the str.
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
 * _get_line - A func that read a line from file description.
 * @fd: first arg
 * @global: sec arg
 * Return: The string, NULL.
 */

char *_get_line(int fd, global_t *global)
{
	static char *left;
	char *line;
	char *next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = _All(fd, left);
	next_line = the_get_line(line);
	left = _ft_left(line);
	global->left = left;
	free(line);
	return (next_line);
}

