#include "shell.h"

/**
 * theAlias - Implements the alias built-in command to manage command aliases
 * @ptr: The command string passed to the alias command
 * @global: Pointer to the global env struct
 * Return: A modified string or NULL.
 */
char *theAlias(char *ptr, global_t *global)
{
	int	i = 0;
	char **str = split(ptr, ' '), *str2 = NULL, *tmp;

	while (str[i] && _strncmp(str[0], "alias", _strlen("alias") + 1))
	{
		if (alias_search(str[i], global))
		{
			tmp = str[i];
			str[i] = _strdup(alias_search(str[i], global));
			free(tmp);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		str2 = _strjoin(str2, str[i]);
		str2 = _strjoin(str2, " ");
		i++;
	}
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	free(ptr);
	return (str2);
}

/**
 * isNew - Checks if a given command string contains a new alias definition
 * @str: The command string to be checked
 * Return: 1 if the string contains a new alias otherwise 0.
 */
int isNew(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
/**
 * the_aliasprint - Searches for an alias and prints its definition
 * @str: The alias name to be searched
 * @global: Pointer to the global env struct
 * Return: The alias definition or NULL
 */
char *the_aliasprint(char *str, global_t *global)
{
	if (alias_search(str, global))
	{
		print(str, 1, 0);
		print("='", 1, 0);
		print(alias_search(str, global), 1, 0);
		print("'", 1, 1);
	}
	return (0);
}

/**
 * helpAlias - Provides help info for the alias function
 * @cmd: Array of cmd strings passed to the alias function
 * @global: Pointer to the global env struct
 */
void helpAlias(char **cmd, global_t *global)
{
	char	*str1, *str2;
	int		i = 1, index;
	alias_t	*node;

	while (cmd[i])
	{
		if (is_new(cmd[i]))
		{
			index = 0;
			str1 = str_copy1(cmd[i], &index, '=');
			index++;
			str2 = _strdup(cmd[i] + index);
			if (aliassearch(str1, global))
			{
				node = aliassearch(str1, global);
				free(str1);
				free(node->value);
				node->value = str2;
			}
			else
			{
				node = malloc(sizeof(alias_t));
				node->next = NULL;
				node->name = str1;
				if (alias_search(str2, global))
				{
					str1 = str2;
					str2 = _strdup(alias_search(str2, global));
					free(str1);
				}
				node->value = str2;
				lstadd_back_alias(&global->alias, node);
			}
		}
		else
			aliassprint(cmd[i], global);
		i++;
	}
}

/**
 * the_alias - Handles the alias command, adding or printing aliases.
 * @cmd: The array of cmd strings passed to the _alias function
 * @global: Pointer to the global env struct
 */
void the_alias(char **cmd, global_t *global)
{
	alias_t *ptr = global->alias;
	int		i = 1;

	global->exit_code = 0;
	if (!cmd[1])
	{
		while (ptr)
		{
			print(ptr->name, 1, 0);
			print("='", 1, 0);
			print(ptr->value, 1, 0);
			print("'", 1, 1);
			ptr = ptr->next;
		}
	}
	else
	{
		help__alias(cmd, global);
		while (cmd[i])
		{
			if (!alias_search(cmd[i], global) && !is_new(cmd[i]))
			{
				print("alias: ", 2, 0);
				print(cmd[i], 2, 0);
				print(" not found", 2, 1);
				global->exit_code = 1;
			}
			i++;
		}
	}
}
