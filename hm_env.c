#include "shell.h"
/**
 * environ - Prints the enviroment.
 * @cmd: An array of str
 * @global: Pointer to env struct
 */
void environ(char **cmd, global_t *global)
{
	env_t *ptr = global->env;

	(void)cmd;
	while (ptr)
	{
		if (ptr->name)
		{
			print(ptr->name, 1, 0);
			print("=", 1, 0);
			print(ptr->value, 1, 1);
		}
		ptr = ptr->next;
	}
	global->exit_code = 0;
}
