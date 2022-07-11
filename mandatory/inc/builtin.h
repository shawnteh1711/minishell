#ifndef BUILTIN_H
# define BUILTIN_H

#include "lexer.h"

typedef	void	(*cmd_handler)(t_shell *shell);
typedef	struct s_builtin_cmd
{
	char		*name;
	cmd_handler	handler;
}	t_builtin_cmd;

int		builtin(t_shell *shell);
void	do_exit(t_shell *shell);
void	do_cd(t_shell *shell);
void	do_pwd(t_shell *shell);
void	do_echo(t_shell *shell);
void	do_env(t_shell *shell);
void	do_export(t_shell *shell);
void	do_unset(t_shell *shell);

#endif