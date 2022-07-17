/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/17 23:35:50 by steh             ###   ########.fr       */
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
	int		j;
	int		k;
	int		nflag;
	char	*ret;
	char	*start;
	// char	*end;
	// char	*target = NULL;

	j = 0;
	nflag = 0;
	echo_cmd(shell);
	ret = ft_strnstr(cmds[0].args[j], "-n", 2);
	if (ret != NULL)
	{
		nflag = 1;
		j++;
	}
	while (cmds[0].args[j] != NULL)
	{
		k = 0;
		if (cmds[0].args[j][k] == '\"')
		{
			k++;
			while (cmds[0].args[j][k] != '\"')
			{
				if (cmds[0].args[j][k] == '$')
				{
					printf("THIS IS A DOLLAR");
				}
				else
					printf("%c", cmds[0].args[j][k]);
				k++;
			}
			break ;
		}
		else if (cmds[0].args[j][k] == '\'')
		{
			while (cmds[0].args[j][k] != '\'')
			{
				printf("%c", cmds[0].args[j][k]);
				k++;
			}
			break ;
		}
		else if (cmds[0].args[j][k] == '$')
		{
			if ((start = strstr(cmds[0].args[j], "$")))
			{
				start += ft_strlen("$");
				// if ((end = strstr(start, "\0")))
				// {
				// 	target = (char *)malloc(end - start + 1);
				// 	ft_memcpy(target, start, end - start );
				// 	target[end - start] = '\0';
				// }
				ret = ft_getenv(shell, start);
				printf("%s", ret);
			}
			// if (target)
			// 	printf( "%s\n", target);
			
		}
		else
			printf("%s", cmds[0].args[j]);
		j++;
	}
	if (nflag == 0)
		printf("\n");
}
