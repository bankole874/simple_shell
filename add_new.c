#include "shell.h"

/**
 *_add_back_env - A function that add a new node to the end of list.
 *@lst: first arg
 *@new: sec arg
 */
void	_add_back_env(env_t **lst, env_t *new)
{
	env_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}

/**
 *_add_back_comm - A func that add a new node to the end of list.
 *@lst: first arg
 *@new: sec arg
 */
void	_add_back_comm(command_t **lst, command_t *new)
{
	command_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}

/**
 *_add_back_alias - A func that add a new node to the end of list.
 *@lst: first arg
 *@new: sec arg
 */
void	_add_back_alias(alias_t **lst, alias_t *new)
{
	alias_t	*item;

	if (!lst || !new)
		return;
	item = *lst;
	if (*lst)
	{
		while (item->next)
			item = item->next;
		item->next = new;
	}
	else
		*lst = new;
}
