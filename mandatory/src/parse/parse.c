/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/06 21:27:33 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	shell_loop(void)
{
	t_shell	shell;
	while (42)
	{
		init();
		if (read_cmd(&shell) == -1)
		{
			break ;
		}
		parse_cmd(&shell);
		exec_cmd(&shell);
	}
}

int	read_cmd(t_shell *shell)
{
	shell->line = readline("test> ");
	if (shell->line == NULL)
		return (-1);
	add_history(shell->line);
	return (0);
}

int	parse_cmd(t_shell *shell)
{
	printf("%s\n", shell->line);
	return (0);
}

int	exec_cmd(t_shell *shell)
{
	return (0);
}
