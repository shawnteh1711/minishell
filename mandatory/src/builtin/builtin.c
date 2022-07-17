/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/17 19:48:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

int	builtin(t_shell *shell)
{
	int					i;
	int					found;
	const t_builtin_cmd	builtins[] = {
	{"exit", do_exit}, {"cd", do_cd},
	{"pwd", do_pwd}, {"echo", do_echo},
	{"env", do_env}, {"export", do_export},
	{"unset", do_unset}, {NULL, NULL}};

	i = 0;
	found = 0;
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

// if cd .. return to two previous path, need to fix
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
	char	pwd[LINE_MAX];

	(void)shell;
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		perror("getcwd error");
	else
		printf("%s\n", pwd);
}

// need to handle double quotes
// need to handle $variable
// if '$VAR' do not expand
// need to handle -n flag

void	do_echo(t_shell *shell)
{
	int		i;
	int		j;
	int		nflag;

	i = 0;
	j = 1;
	nflag = 0;
	echo_cmd(shell);
	if (ft_strnstr(cmds[0].args[0], "-n", 2))
		nflag = 1;
	while (cmds[0].args[j] != NULL)
	{
		// if (cmds[0].args[j] == '\"')
		// 	printf("double quotes\n");
		// else if (cmds[0].args[j] == '\'')
		// 	printf("single quotes\n");
		// else if (cmds[0].args[j] == '$')
		// 	printf("dollar sign\n");
		printf("%s\n", cmds[0].args[j]);
		printf("%c\n", cmds[0].args[j][0]);
		j++;
	}
	

}
