#include "shell.h"
/**
 * env - Print the enviroment var to the standard output
 * @cmd: An array of str representing the command and its argument
 * @global: Pointer to the globlal env struct
 */
void env(char **cmd, global_t *global)
{
	env_t *ptr = global->env;

	(void)cmd;
	while (ptr)
	{
		if (ptr->name)
		{
			_print(ptr->name, 1, 0);
			_print("=", 1, 0);
			_print(ptr->value, 1, 1);
		}
		ptr = ptr->next;
	}
	global->exit_code = 0;
}

