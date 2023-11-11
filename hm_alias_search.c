#include "shell.h"

/**
 * the_alias_search - Finds an alias in the global alias list
 * @str: The name of the alias to find
 * @global: Pointer to the global env
 * Return: int, NULL otherwise
 */

char *the_alias_search(char *str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_Str_comp(str, ptr->name, _Str_len(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}
/**
 * thealiassearch - Finds an alias in the global alias list
 * @str: The name of the alias to find.
 * @global: Pointer to the global env
 * Return: Pointer, NULL
 */

alias_t	*thealiassearch(char *str, global_t *global)
{
	alias_t	*ptr;

	ptr = global->alias;
	while (ptr)
	{
		if (ptr->name && !_Str_len(str, ptr->name, _Str_len(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
