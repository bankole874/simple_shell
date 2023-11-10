#include "shell.h"

/**
 *help_var_repl - A variables replacement.
 *@ptr: arg 1.
 *@global: arg 2.
 *Return: the pointer to modified string.
 */
char *help_var_repl(char *ptr, global_t *global)
{
	int	i = 0;
	char **str = the_split(ptr, ' '), *str2 = NULL, *tmp;

	while (str[i])
	{
		if (str[i][0] == '$' && str[i][1])
		{
			tmp = str[i];
			if (env_search(str[i] + 1, global))
				str[i] = _Str_dup(env_search(str[i] + 1, global));
			else
				str[i] = _Str_dup("");
			free(tmp);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		str2 = _Str_conc(str2, str[i]);
		str2 = _Str_conc(str2, " ");
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
 *var_repl - the variables replacement.
 *@ptr: arg 1.
 *@global: arg 2.
 *Return: pointer to modified string
 */
char	*var_repl(char *ptr, global_t *global)
{
	char	*str = NULL, *tmp;
	int		i = 0, m = 0;

	if (!ptr)
		return (NULL);
	while (ptr[i])
	{
		if (!_Str_comp(ptr + i, "$$", 2) || !_Str_comp(ptr + i, "$?", 2))
		{
			if (!_Str_comp(ptr + i, "$$", 2))
				tmp = _itoa(global->pid);
			else if (!_Str_comp(ptr + i, "$?", 2))
				tmp = _itoa(global->exit_code);
			ptr[i] = 0;
			str = _Str_conc(str, ptr + m);
			str = _Str_conc(str, tmp);
			free(tmp);
			ptr[i] = '$';
			i++;
			m = i + 1;
		}
		if (ptr[i])
			i++;
	}
	if (!str)
		str = _Str_dup(ptr);
	free(ptr);
	return (help_var_repl(str, global));
}
