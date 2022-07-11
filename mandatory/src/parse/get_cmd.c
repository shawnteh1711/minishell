/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:37:28 by steh              #+#    #+#             */
/*   Updated: 2022/07/11 08:37:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	get_command(int i, t_shell *shell)
{
	int		j;
	int		inword;
	int		stat;

	j = 0;
	stat = 0;
	while (*shell->cmdline != '\0')
	{
		while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
			shell->cmdline++;
		cmds[i].args[j] = shell->avptr;
		while (*shell->cmdline != '\0' && *shell->cmdline != ' '
			&& *shell->cmdline != '\t' && *shell->cmdline != '>'
			&& *shell->cmdline != '<' && *shell->cmdline != '|'
			&& *shell->cmdline != '&' && *shell->cmdline != '\n')
		{
			*shell->avptr++ = *shell->cmdline++;
			inword = 1;
		}
		*shell->avptr++ = '\0';
		stat = get_command2(&i, &j, &inword, shell);
		if (stat == 1)
			return ;
	}
}

int	get_command2(int *i, int *j, int *inword, t_shell *shell)
{
	while (*shell->cmdline)
	{
		if (*shell->cmdline == ' ' || *shell->cmdline == '\t')
		{
			*inword = 0;
			(*j)++;
			break ;
		}
		else if (*shell->cmdline == '<' || *shell->cmdline == '>'
			|| *shell->cmdline == '|' || *shell->cmdline == '&'
			|| *shell->cmdline == '\n')
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
