#ifndef SHELL_H
#define SHELL_H
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct command_s - singly linked list
 * @path: the path.
 * @args: the args.
 * @tmp: the tmp.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for command.
 */

typedef struct command_s
{
	char		        *path;
	char		        **args;
	char				*tmp;
	struct command_s	*next;
} command_t;

/**
 * struct alias_s - singly linked list
 * @name: the nmae.
 * @value: the value.
 * @next: points to the next node.
 *
 * Description: singly linked list node structure
 * for alias.
 */

typedef struct alias_s
{
	char		    *name;
	char		    *value;
	struct alias_s	*next;
} alias_t;

/**
 * struct env_s - singly linked list
 * @name: the name.
 * @value: the value.
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for env.
 */
typedef struct env_s
{
	char		    *name;
	char		    *value;
	struct env_s	*next;
} env_t;

/**
 * struct global_s - global variable.
 * @commands: the commands.
 * @env: the env.
 * @alias: the alias.
 * @exit_code: the exit code.
 * @pid: the pid.
 * @name: the name.
 * @envp: the envp.
 * @cmd: the cmd.
 * @left: the left.
 * @n: the line num.
 * @fd: the fd.
 *
 * Description: global variable.
 */
typedef struct global_s
{
	command_t   *commands;
	env_t       *env;
	alias_t     *alias;
	int		    exit_code;
	pid_t       pid;
	char        *name;
	char        **envp;
	char		*cmd;
	char		*left;
	int			n;
	int			fd;
} global_t;

# define BUFFER_SIZE 1024

char	*_get_line(int fd, global_t *global);
size_t	_my_str_len(const char *s);
char	*_my_str_conc(char *s1, char *s2);
char	*_my_str_chrc(const char *s, int c);
void	*_my_memcpy(void *dst, const void *src, size_t n);
char	*rem_comm(char *ptr, global_t *global, int fd);
void	_add_back_env(env_t **lst, env_t *new);
void	initEnv(char **envp, global_t *global);
char	*envSearch(char	*str, global_t *global);
size_t	_Str_len(const char *s);
int     _Str_comp(const char *s1, const char *s2, size_t n);
void	_add_back_comm(command_t **lst, command_t *new);
void	_add_back_alias(alias_t **lst, alias_t *new);
char	**the_split(char const *s, char c);
char	*_Str_dup(const char *s1);
char	*theAlias(char *ptr, global_t *global);
char	*_Str_conc(char *s1, char *s2);
char	*the_itoa(int n);
char    *var_repl(char *ptr, global_t *global);
void	getCommands(char *ptr, global_t *global);
int	execBuiltin(char **args, global_t *global);
void	exe(global_t *global);
int     printError(char *cmd, char *msg, global_t *global);
void    environ(char **cmd, global_t *global);
void	_cd(char **cmd, global_t *global);
void    myExit(char **cmd, global_t *global);
void	freeAll(global_t *global);
void	freeCommands(global_t *global);
int	_print(char *str, int fd, int new);
int	_theatoi(char *s);
void	_Set_env(char **cmd, global_t *global);
env_t	*envSearches(char *str, global_t *global);
void	_Unset_env(char **cmd, global_t *global);
void	Print_num_fd(int n, int fd);
char	*strCopy1(char	*str, int *index, char a);
void	the_alias(char **cmd, global_t *global);
char	*the_alias_search(char	*str, global_t *global);
alias_t	*thealiassearch(char	*str, global_t *global);
int	is_lo_op(char *str);
char	**the_advanced_split(char *str, global_t *global);
void	exe_logical_operators(char **str, global_t *global);
char	*getPath(char *str, global_t *global);
void	execBinary(command_t *command, global_t *global);
extern char **_env;

#endif

