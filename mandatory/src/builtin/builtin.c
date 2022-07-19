/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:16:52 by steh              #+#    #+#             */
/*   Updated: 2022/07/19 22:52:25 by steh             ###   ########.fr       */
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

char	*ft_split_quot(t_shell *shell, char **line, char *quotes)
{
	char	*start;
	char	*end;
	char	*target;
	char	*ret;
	
	end = NULL;
	target = NULL;
	if ((start = strstr(*line, quotes)))
	{
		start += strlen(quotes);
		if ((end = strstr(start, quotes)))
		{
			target = (char *)malloc(end - start + 1);
			ft_memcpy(target, start, end - start + 1);
			target[end - start] = '\0';
		}
	}
	if (target && ft_strcmp(quotes, "\'") == 0)
		printf("%s", target);
	else if (target && ft_strcmp(quotes, "\"") == 0)
	{
		if (target[0] == '$')
			target += ft_strlen("$");
		ret = ft_getenv(shell, target);
		if (ret == NULL)
			printf("%s", target);
		else
			printf("%s", ret);
	}
	// free(target);
	return (end++);
}

void	do_echo(t_shell *shell)
{
	int			j;
	int			k;
	int			nflag;
	char		*ret;
	char		*start;
	t_command	cmds_cp[PIPELINE];

	j = 0;
	nflag = 0;
	echo_cmd(shell);
	ft_memset(cmds_cp, 0, sizeof(cmds_cp));
	cmds_cp[0].args[j] = cmds[0].args[j];
	while (cmds_cp[0].args[j] != NULL)
	{
		k = 0;
		ret = ft_strnstr(cmds_cp[0].args[j], "-n", 2);
		if (ret != NULL)
		{
			nflag = 1;
			j++;
		}
		while (cmds_cp[0].args[j][k] != '\0')
		{
			if (cmds_cp[0].args[j][k] == '$')
			{
				if ((start = ft_strstr(cmds_cp[0].args[j], "$")))
				{
					char arr[10];
					int	id = 0;
					start += ft_strlen("$");
					while (ft_isalpha(*start))
					{
						arr[id] = *start;
						id++;
						start++;;
					}
					ret = ft_getenv(shell, arr);
					printf("%s", ret);
					cmds_cp[0].args[j] = start;
				}
			}
			else if (cmds_cp[0].args[j][k] == '\"')
			{
				cmds_cp[0].args[j] = ft_split_quot(shell, &cmds_cp[0].args[j], "\"");
			}
			else if (cmds_cp[0].args[j][k] == '\'')
			{
				cmds_cp[0].args[j] = ft_split_quot(shell, &cmds_cp[0].args[j], "\'");
			}
			else
				printf("%c", cmds_cp[0].args[j][k]);
			k++;
		}
		j++;
	}
	if (nflag == 0)
		printf("\n");
}
