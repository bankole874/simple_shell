#include "shell.h"
/**
 *the_handler - The signal handler for Ctrl+C=SIGINT.
 *@sig: first arg
 */
void the_handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}

/**
 *main - the main function.
 *@ac: The no of arguments
 *@av: The array of arg strings
 *@env: The array of env string
 * Return: 0 always
 */

int main(int ac, char **av, char **env)
{
	char		*ptr, fd = 0;
	global_t	*global;

	signal(SIGINT, the_handler);
	global = malloc(sizeof(global_t));
	global->name = av[0];
	if (ac > 1)
	{
		fd = open(av[1], O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			_print(global->name, 2, 0);
			_print(": ", 2, 0);
			print_num_fd(global->n, 2);
			_print(": Can't open ", 2, 0);
			_print(av[1], 2, 1);
			return (127);
		}
	}
	initEnv(env, global);
	global->fd = fd;
	while (1)
	{
		if (isatty(fd))
			write(1, "$ ", 2);
		ptr = _get_line(fd, global);
		ptr = rem_comm(ptr, global, fd);
		global->cmd = ptr;
		getCommands(ptr, global);
		exe(global);
		global->n++;
		free(ptr);
	}
	freeAll(global);
	return (0);
}
