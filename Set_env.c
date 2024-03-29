#include "shell.h"

/**
 * _Set_env - sets variable env.
 * @cmd: first argument.
 * @global: second argument.
 */

void _Set_env(char **cmd, global_t *global)
{
	int i = 0;
	env_t *tmp;

	(void)global;
	while (cmd[i])
		i++;
	if (i != 3)
	{
		_print("Incorrect number of arguements", 2, 1);
		global->exit_code = 127;
	}
	else
	{
		global->exit_code = 0;
		tmp = envSearches(cmd[1], global);
		if (tmp)
		{
			free(tmp->value);
			tmp->value = _Str_dup(cmd[2]);
		}
		else
		{
			tmp = malloc(sizeof(env_t));
			tmp->next = NULL;
			tmp->name = _Str_dup(cmd[1]);
			tmp->value = _Str_dup(cmd[2]);
			_add_back_env(&global->env, tmp);
		}
	}
}

/**
 * _Unset_env - unset var env.
 * @cmd: first argument.
 * @global: second argument.
 */

void _Unset_env(char **cmd, global_t *global)
{
	env_t *tmp;
	int i = 1;

	if (!cmd[1])
	{
		_print("Too few arguements", 2, 1);
		global->exit_code = 127;
	}
	else
	{
		while (cmd[i])
		{
			tmp = envSearches(cmd[i], global);
			if (tmp)
			{
				free(tmp->name);
				free(tmp->value);
				tmp->name = NULL;
				tmp->value = NULL;
				global->exit_code = 0;
			}
			else
				global->exit_code = 127;
			i++;
		}
	}
}
