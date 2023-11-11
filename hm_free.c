#include "shell.h"

/**
 * freeCommands - frees command structures.
 * @global: first argument.
 */

void freeCommands(global_t *global)
{
	command_t *tmp = global->commands, *tmp2;
	char **str;
	int i;

	while (tmp)
	{
		i = 0;
		tmp2 = tmp->next;
		free(tmp->path);
		free(tmp->tmp);
		str = tmp->args;
		while (str && str[i])
			free(str[i++]);
		free(str);
		free(tmp);
		tmp = tmp2;
	}
	global->commands = NULL;
}

/**
 * freeAlias - frees alias structures.
 * @global: first argument.
 */

void    freeAlias(global_t *global)
{
	alias_t	*tmp = global->alias, *tmp2;

	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = tmp2;
	}
	global->alias = NULL;
}

/**
 * freeEnv - frees env structures.
 * @global: first argument.
 */

void freeEnv(global_t *global)
{
	env_t	*tmp = global->env, *tmp2;

	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
		tmp = tmp2;
	}
	global->env = NULL;
}

/**
 * freeAll - Free all.
 * @global: first argument.
 */

void freeAll(global_t *global)
{
	freeCommands(global);
	freeEnv(global);
	freeAlias(global);
	free(global->cmd);
	free(global->left);
	close(global->fd);
	free(global);
}

