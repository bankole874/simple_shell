#include "shell.h"

/**
*execBuiltin - run built-in command.
*@args: arg 1.
*@global:arg 2.
* Return: 1 if the command is a built-in.
*/

int execBuiltin(char **args, global_t *global)
{
	char	*cmd = args[0];

	if (!cmd)
		return (0);
	else if (!_Str_comp("env", cmd, _Str_len("env") + 1))
	{
		environ(args, global);
		return (1);
	}
	else if (!_Str_comp("cd", cmd, _Str_len("cd") + 1))
	{
		_cd(args, global);
		return (1);
	}
	else if (!_Str_comp("exit", cmd, _Str_len("exit") + 1))
	{
		myExit(args, global);
		return (1);
	}
	else if (!_Str_comp("setenv", cmd, _Str_len("setenv") + 1))
	{
		_Set_env(args, global);
		return (1);
	}
	else if (!_Str_comp("unsetenv", cmd, _Str_len("unsetenv") + 1))
	{
		_Unset_env(args, global);
		return (1);
	}
	else if (!_Str_comp("alias", cmd, _Str_len("alias") + 1))
	{
		the_alias(args, global);
		return (1);
	}
	return (0);
}

