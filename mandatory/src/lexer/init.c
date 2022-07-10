/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:15:47 by steh              #+#    #+#             */
/*   Updated: 2022/07/10 21:58:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

void	setup(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	init(t_shell *shell)
{
	ft_memset(cmds, 0, sizeof(cmds));
	ft_memset(shell->avline, 0, sizeof(shell->avline));
	ft_memset(shell->infile, 0, sizeof(shell->infile));
	ft_memset(shell->outfile, 0, sizeof(shell->outfile));
	shell->avptr = shell->avline;
	shell->append = 0;
	shell->cmd_count = 0;
	
}
