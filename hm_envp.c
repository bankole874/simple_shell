#include "shell.h"

/**
 * strCopy1 - Copies a substring from the input string
 * @str: The input string from which the substring is copied
 * @index: A pointer to index from which copying starts
 * @a: The character at which copying stops.
 * Return: The copied substring
 */

char *strCopy1(char *str, int *index, char a)
{
	int i;
	int start;
	char *ptr;
	int y;

	i = *index;
	start = *index;
	while (str[i] && str[i] != a)
	{
		i++;
		*index = *index + 1;
	}
	ptr = malloc(i + 1);
	y = 0;
	while (y < i)
		ptr[y++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * initEnv - Initialize the env variables
 * @envp: The arr of env var passed to the program
 * @global: A pointer to global state struct
 */

void initEnv(char **envp, global_t *global)
{
	int i;
	env_t *env;
	env_t *head;
	int index;

	i = 0;
	head = NULL;
	while (envp && envp[i])
	{
		index = 0;
		env = malloc(sizeof(env_t));
		env->name = strCopy1(envp[i], &index, '=');
		index++;
		env->value = strCopy1(envp[i], &index, 0);
		env->next = NULL;
		_add_back_env(&head, env);
		i++;
	}
	global->env = head;
	global->commands = NULL;
	global->exit_code = 0;
	global->pid = getpid();
	global->alias = NULL;
	global->envp = envp;
	global->n = 1;
}

/**
 * envSearch - Searches for an env var by name
 * @str: The name of the env var to search for
 * @global: A pointer to the global state struct
 * Return: The value of the env var if found, NULL if not found
 */

char *envSearch(char *str, global_t *global)
{
	env_t *ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_Str_comp(str, ptr->name, _Str_len(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 * envSearches - Searches for an env var by name and returns
 * @str: The name of the env var to search for
 * @global: A pointer to the global state struct
 * Return: A pointer to the env var node if found, NULL if not found
 */

env_t	*envSearches(char *str, global_t *global)
{
	env_t *ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_Str_comp(str, ptr->name, _Str_len(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}

