/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_backup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/26 10:33:49 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

// int	parse_cmd(t_shell *shell)
// {
// 	int	i;
// 	int	stat;

// 	i = 0;
// 	while (shell->cmdline)
// 	{
// 		if (builtin(shell))
// 			continue ;
// 		get_command(0, shell);
// 		if (check(shell, "<"))
// 		{
// 			if (check(shell, "<"))
// 				shell->heredoc = 1;
// 			else
// 				// getname(shell->infile, shell);
// 				getname(cmds[i].infile, shell);
// 		}
// 		if (check(shell, ">"))
// 		{
// 			if (check(shell, ">"))
// 				shell->append = 1;
// 			// getname(shell->outfile, shell);
// 			getname(cmds[i].outfile, shell);
// 		}
// 		stat = parse_cmd2(shell, i);
// 		if (stat)
// 			return (stat);
// 	}
// 	return (0);
// }

// int	parse_cmd2(t_shell *shell, int i)
// {
// 	i = 1;
// 	while (i < PIPELINE)
// 	{
// 		if (check(shell, "|"))
// 			get_command(i, shell);
// 		else
// 			break ;
// 		++i;
// 	}	
// 	if (check(shell, "\0"))
// 	{
// 		shell->cmd_count = i;
// 		return (shell->cmd_count);
// 	}
// 	else
// 	{
// 		printf("Command line syntax error\n");
// 		return (-1);
// 	}
// }
