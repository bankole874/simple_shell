#include "shell.h"
/**
 * printError - Prints error message
 * @cmd: command where the error occurred
 * @msg: error message to be printed
 * @global: A pointer to the global struct
 * Return: 1
 */
int	printError(char *cmd, char *msg, global_t *global)
{
	write(2, global->name, _strlen(global->name));
	write(2, ": ", 2);
	putnbr_fd(global->n, 2);
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, _strlen(msg));
	write(2, "\n", 1);
	return (1);
}

/**
 * _print - prints a string to a given file descriptor
 * @str: string
 * @fd: file descriptor
 * @new: flag indicating whether to append a newline  or not
 * Return: int
 */

int _print(char *str, int fd, int new)
{
	write(fd, str, _strlen(str));
	if (new)
		return (write(fd, "\n", 1));
	return (1);
}
