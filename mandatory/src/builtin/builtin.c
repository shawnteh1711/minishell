/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/15 21:49:02 by steh             ###   ########.fr       */
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
	char	pwd[LINE_MAX];

	(void)shell;
	if (getcwd(pwd, sizeof(pwd)) == NULL)
		perror("getcwd error");
	else
		printf("%s\n", pwd);
}

// need to handle double quotes
// need to handle $variable
// need to handle -n flag
void	do_echo(t_shell *shell)
{
	int		i;
	int		j;
	int		newline;
	char	*line;

	i = 0;
	line = shell->cmdline;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '-' && line[i + 1] == 'n')
		{
			newline = 1;
			i++;
		}
		if (line[i] == '"')
		{
			j = i + 1;
			while (line[j] != '\0')
			{
				if (line[j] == '"')
					break ;
				j++;
			}
			i++;
			j--;
			while (i < j)
			{
				write(1, &line[i], sizeof(&line[i]));
				i++;
			}
		}
		else
			write(1, &line[i], sizeof(&line[i]));
		i++;
	}
}
