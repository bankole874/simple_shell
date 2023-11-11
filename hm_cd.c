#include "shell.h"

/**
 *helpCD - help cd function.
 *@cmd: The pointer to the pointer of the command.
 *@global: The second argument.
 */
void helpCD(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;

	if (!envSearch("OLDPWD", global))
		_print(envSearch("PWD", global), 1, 1);
	else
	{
		tmp = getcwd(0, 0);
		if (chdir(envSearch("OLDPWD", global)))
		{
			_print(global->name, 2, 0);
			_print(": ", 2, 0);
			Print_num_fd(global->n, 2);
			_print(": cd: can't cd to ", 2, 0);
			_print(cmd[1], 2, 1);
			free(tmp);
			global->exit_code = 2;
		}
		else
		{
			t[2] = envSearch("OLDPWD", global);
			_print(t[2], 1, 1);
			_Set_env(t, global);
			t[1] = "OLDPWD";
			t[2] = tmp;
			_Set_env(t, global);
			free(tmp);
		}
	}
}

/**
 *helpCD2 - help cd function.
 *@cmd: The pointer to the pointer of the command.
 *@global: The pointer to the global state struct.
 */
void helpCD2(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;

	tmp = getcwd(0, 0);
	if (chdir(cmd[1]))
	{
		_print(global->name, 2, 0);
		_print(": ", 2, 0);
		Print_num_fd(global->n, 2);
		_print(": cd: can't cd to ", 2, 0);
		_print(cmd[1], 2, 1);
		free(tmp);
		global->exit_code = 2;
	}
	else
	{
		t[2] = getcwd(0, 0);
		_Set_env(t, global);
		free(t[2]);
		t[1] = "OLDPWD";
		t[2] = tmp;
		_Set_env(t, global);
		free(tmp);
	}
}

/**
 *_cd - change the current directory.
 *@cmd: arg 1.
 *@global: arg 2.
 */
void _cd(char **cmd, global_t *global)
{
	char *t[4], *tmp;

	global->exit_code = 0;
	t[0] = "setenv";
	t[1] = "PWD";
	t[3] = NULL;
	if (!cmd[1])
	{
		if (envSearch("HOME", global))
		{
			tmp = getcwd(0, 0);
			if (chdir(envSearch("HOME", global)))
			{
				_print(global->name, 2, 0);
				_print(": ", 2, 0);
				Print_num_fd(global->n, 2);
				_print(": cd: can't cd to ", 2, 0);
				_print(cmd[1], 2, 1);
				free(tmp);
				global->exit_code = 2;
			}
			else
			{
				t[2] = envSearch("HOME", global);
				_Set_env(t, global);
				t[1] = "OLDPWD";
				t[2] = tmp;
				_Set_env(t, global);
				free(tmp);
			}
		}
	}
	else
	{
		if (cmd[1][0] == '-' && !cmd[1][1])
			helpCD(cmd, global);
		else
			helpCD2(cmd, global);
	}
}

