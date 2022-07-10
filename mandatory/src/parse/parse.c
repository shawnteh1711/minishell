/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/10 21:50:28 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"


void	shell_loop()
{
	t_shell	shell;

	while (42)
	{
		init(&shell);
		if (read_cmd(&shell) == -1)
		{
			break ;
		}
		parse_cmd(&shell);
		print_command(&shell);
		exec_cmd(&shell);
	}
}

int	read_cmd(t_shell *shell)
{
	shell->cmdline = readline("test> ");
	if (shell->cmdline == NULL)
		return (-1);
	add_history(shell->cmdline);
	return (0);
}

int	parse_cmd(t_shell *shell)
{
	int	i;

	get_command(0, shell);
	if (check(shell, "<"))
	{
		getname(shell->infile, shell);
	}
	
	i = 1;
	while (i < PIPELINE)
	{
		if (check(shell, "|"))
			get_command(i, shell);
		else
			break ;
		++i;
	}

	if (check(shell, ">"))
	{
		if (check(shell, ">"))
		{
			shell->append = 1;
		}
		getname(shell->outfile, shell);
	}
	
	if (check(shell, "\0"))
	{
		shell->cmd_count = i;
		return (shell->cmd_count);
	}
	else
	{
		fprintf(stderr, "Command line syntax error\n");
		return (-1);
	}
	return (0);
}

void	get_command(int i, t_shell *shell)
{
	int		j;
	int		inword;

	j = 0;
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
		// get_command2(i, j, inword, shell);
		switch (*shell->cmdline)
		{
		case ' ':
		case '\t':
			inword = 0;
			j++;
			break;
		case '<':
		case '>':
		case '|':
		case '&':
		case '\n':
			if (inword == 0)
				cmds[i].args[j] = NULL;
			return ;
		default:
			return ;
		}
	}
}

void	get_command2(int i, int j, int inword, t_shell *shell)
{
	if (*shell->cmdline == ' ' || *shell->cmdline == '\t')
	{
		inword = 0;
		j++;
	}
	else if (*shell->cmdline == '<' || *shell->cmdline == '>'
		|| *shell->cmdline == '|' || *shell->cmdline == '&'
		|| *shell->cmdline == '\n')
	{
		if (inword == 0)
		{
			cmds[i].args[j] = NULL;
		}
	}
	else
		return ;
}
