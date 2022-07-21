/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:37:28 by steh              #+#    #+#             */
/*   Updated: 2022/07/21 11:08:48 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

char	*ck_cmdline(t_shell *shell, char *line, int *inword)
{
	while (*line != '\0' && *line != '\t' && *line != ' '
		&& *line != '>' && *line != '<' && *line != '|'
		&& *line != '&' && *line != '\n')
	{
		*shell->avptr++ = *line++;
		*inword = 1;
	}
	return (line);
}

void	get_command(int i, t_shell *shell)
{
	int		j;
	int		inword;
	int		stat;
	char	*line;

	j = 0;
	stat = 0;
	line = shell->cmdline;
	while (*line != '\0')
	{
		while (*line == ' ' || *line == '\t')
			line++;
		cmds[i].args[j] = shell->avptr;
		line = ck_cmdline(shell, line, &inword);
		*shell->avptr++ = '\0';
		stat = get_command2(&i, &j, &inword, line);
		if (stat == 1)
			return ;
	}
}

int	get_command2(int *i, int *j, int *inword, char *line)
{
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
		{
			*inword = 0;
			(*j)++;
			break ;
		}
		else if (*line == '<' || *line == '>'
			|| *line == '|' || *line == '&'
			|| *line == '\n')
		{
			if (*inword == 0)
				cmds[*i].args[*j] = NULL;
			return (1);
		}
		else
			return (1);
	}
	return (0);
}
