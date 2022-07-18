/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:23:44 by steh              #+#    #+#             */
/*   Updated: 2022/07/18 17:19:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	dollar(t_shell *shell, char *line, int *i, int *j)
{
	char	*ret;
	char	s[10];
	int		k;

	if (line[*i] == '$')
		*j = *i + 1;
	while (line[*j] != '\0')
		(*j)++;
	ft_memset(s, 0, sizeof(s));
	k = 0;
	(*i)++;
	while ((*i) < (*j))
	{
		s[k] = line[*i];
		k++;
		(*i)++;
	}
	s[k] = '\0';
	ret = ft_getenv(shell, s);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		perror("getenv dollar");
}

void	dollar2(t_shell *shell, char *line, int *i, int *j)
{
	char	*ret;
	char	s[10];
	int		k;

	if (line[*j] == '$')
	{
		(*i)++;
		(*j)++;
	}
	while (line[*j] != '\"')
		(*j)++;
	ft_memset(s, 0, sizeof(s));
	k = 0;
	(*i)++;
	while ((*i) < (*j))
	{
		s[k] = line[*i];
		k++;
		(*i)++;
	}
	s[k] = '\0';
	ret = ft_getenv(shell, s);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		perror("getenv dollar");
}

char	*ck_cmd(t_shell *shell, char *line)
{
	while (*line != '\0' && *line != '\t' && *line != ' '
		&& *line != '>' && *line != '<' && *line != '|'
		// && *line != '\"' && *line != '\'' && *line != '$'
		&& *line != '&' && *line != '\n')
		*shell->avptr++ = *line++;
	return (line);
}

void	echo_cmd(t_shell *shell)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = shell->cmdline;
	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\t')
			line++;
		// while (*line == '\"' || *line == '\'' || *line == '$')
		// 	line++;
		cmds[i].args[j] = shell->avptr;
		line = ck_cmd(shell, line);
		*shell->avptr++ = '\0';
		echo_cmd2(&i, &j, line);
	}
}

void	echo_cmd2(int *i, int *j, char *line)
{
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
		{
			(*j)++;
			break ;
		}
		// if (*line == '\"' || *line == '\'' || *line == '$')
		// {
		// 	(*j)++;
		// 	break ;
		// }
		else if (*line == '<' || *line == '>' || *line == '|'
			|| *line == '&' || *line == '\n')
		{
			cmds[*i].args[*j] = NULL;
			return ;
		}
		else
			return ;
	}
	return ;
}

// multiple echo -nnnnnnnn
// void	echo_n()
// {
// }