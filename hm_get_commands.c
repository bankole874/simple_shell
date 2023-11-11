#include "shell.h"

/**
 * getPath - retrieves the path of a command.
 * @str: first argument.
 * @global: second argument.
 * Return: path
 */

char *getPath(char *str, global_t *global)
{
	char *ptr = _Str_dup(str), **paths, *tmp;
	int i = 0;

	if (!access(ptr, F_OK))
	{
		if (!_Str_comp(ptr, "/", 1) || !_Str_comp(ptr, "./", 2) ||
			!_Str_comp(ptr, "../", 3))
			return (ptr);
	}
		paths = the_split(envSearch("PATH", global), ':');
	if (!paths)
	{
		free(ptr);
		return (0);
	}
	while (paths[i])
	{
		tmp = _Str_conc(_Str_dup(paths[i]), "/");
		tmp = _Str_conc(tmp, ptr);
		if (!access(tmp, F_OK))
		{
			i = 0;
			while (paths[i])
				free(paths[i++]);
			free(paths);
			free(ptr);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(ptr);
	return (NULL);
}

/**
 * getPaths - retrieves the full paths of commands.
 * @global: second argument.
 */

void getPaths(global_t *global)
{
	command_t *tmp = global->commands;

	while (tmp)
	{
		if (tmp->args)
			tmp->path = getPath(tmp->args[0], global);
		tmp = tmp->next;
	}
}

/**
 * getCommands - Parse and store the commands.
 * @ptr: first argument.
 * @global: second argument.
 */

void getCommands(char *ptr, global_t *global)
{
	char **commands;
	int i = 0;
	command_t *node;

	freeCommands(global);
	if (!ptr)
		return;
	commands = the_split(ptr, ';');
	while (commands[i])
	{
		commands[i] = var_repl(theAlias(commands[i], global), global);
		node = malloc(sizeof(command_t));
		node->path = NULL;
		node->next = NULL;
		if (commands[i] && is_lo_op(commands[i]))
		{
			node->args = NULL;
			node->tmp = _Str_dup(commands[i]);
		}
		else
		{
			node->args = the_split(commands[i], ' ');
			node->tmp = NULL;
		}
		_add_back_comm(&global->commands, node);
		i++;
	}
	i = 0;
	while (commands[i])
		free(commands[i++]);
	free(commands);
	getPaths(global);
}

