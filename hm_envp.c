#include "shell.h"

/**
 * *strCopy1 - Create a copy of a substring from the input string
 * @str: The input string
 * @idx: A pointer to index from which copying starts
 * @a: The character at which copying stops.
 * Return: The copied substring
 */
char	*strCopy1(char	*str, int *index, char a)
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
 * initEnv - Initializes the env variables
 * @envp: array of env var passed
 * @global: pointer to global struct
 */

void	initEnv(char **envp, global_t *global)
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
		env->name = str_copy1(envp[i], &index, '=');
		index++;
		env->value = str_copy1(envp[i], &index, 0);
		env->next = NULL;
		lstadd_back_env(&head, env);
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
 * envSearch - finds an env var by name
 * @str: The name of the env var to find
 * @gloabal: A pointer to the global struct
 * Return: int, NULL
 */

char	*envSearch(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 * envSearches - Finds an env var by name
 * @str: The name of the env var to find
 * @global: A pointer to the global struct
 * Return: A pointer, NULL
 */

env_t *envSearches(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
