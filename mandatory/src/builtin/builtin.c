/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/11 19:58:07 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

int	builtin(t_shell *shell)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	t_builtin_cmd builtins[] =
	{
		{"exit", do_exit},
		{"cd", do_cd},
		{"pwd", do_pwd},
		{"echo", do_echo},
		{"env", do_env},
		{"export", do_export},
		{"unset", do_unset},
		{NULL, NULL}
	};
	while (builtins[i].name != NULL)
	{
		if (check(shell, builtins[i].name))
		{
			builtins[i].handler(shell);
			found = 1;
			break ;
		}
		i++;
	}
	return (found);
}

void	do_exit(t_shell *shell)
{
	(void)shell;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

// error if more than one word directory
// need to fix assign_cmd
void	do_cd(t_shell *shell)
{
	char	*tmp;
	
	assign_cmd(shell);
	if (cmds[0].args[0] == NULL)
	{
		tmp = getenv("HOME");
		chdir(tmp);
	}
	else
	{
		if (chdir(cmds[0].args[0]) != 0)
			perror("chdir error");
		else
			chdir(cmds[0].args[0]);
	}
}

void	do_pwd(t_shell *shell)
{
	(void)shell;
	char	pwd[LINE_MAX];
	
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		perror("getcwd error");
	else
		printf("%s\n", pwd);
}

void	do_echo(t_shell *shell)
{
	(void)shell;
	char	*tmp;
	
	assign_cmd(shell);
	tmp = cmds[0].args[0];
	if (ft_strcmp(tmp, "-n") == 0)
	{
		printf("%s", cmds[0].args[1]);
	}
	else
	{
		printf("%s\n", tmp);
	}
}
