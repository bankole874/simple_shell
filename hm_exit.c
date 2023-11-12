#include "shell.h"

/**
 * isNum - Number.
 * @str: first argument.
 * Return: 1.
 */

int isNum(char *str)
{
	int i = 0;

	if (str[0] && (str[0] == '-' || str[0] == '+'))
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] == '0')
	{
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * myExit - exits the shell.
 * @cmd: first argument;
 * @global: second argument.
 */

void myExit(char **cmd, global_t *global)
{
	int n;

	if (!cmd[1])
	{
		n = global->exit_code;
		freeAll(global);
		exit(n);
	}
	else
	{
		if (!isNum(cmd[1]) || _theatoi(cmd[1]) < 0)
		{
			_print(global->name, 2, 0);
			_print(": ", 2, 0);
			print_num_fd(global->n, 2);
			_print(": exit: Illegal number: ", 2, 0);
			_print(cmd[1], 2, 1);
			global->exit_code = 2;
		}
		else
		{
			n = _theatoi(cmd[1]);
			freeAll(global);
			exit((unsigned char)n);
		}
	}
}

