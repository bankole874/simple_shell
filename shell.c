#include "shell.h"
/**
 *the_handler - signal handler for Ctrl+C=SIGINT.
 *@sig: arg 1.
 */
void the_handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}

/**
 *main - the main function.
 *@ac: The no of arguments
 *@av: Array of arg strings
 *@env: Array of env string
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
			print(global->name, 2, 0);
			print(": ", 2, 0);
			putnbr_fd(global->n, 2);
			print(": Can't open ", 2, 0);
			print(av[1], 2, 1);
			return (127);
		}
	}
	init_env(env, global);
	global->fd = fd;
	while (1)
	{
		if (isatty(fd))
			write(1, "$ ", 2);
		ptr = _getline(fd, global);
		ptr = remove_comments(ptr, global, fd);
		global->cmd = ptr;
		get_commands(ptr, global);
		executing(global);
		global->n++;
		free(ptr);
	}
	free_all(global);
	return (0);
}
