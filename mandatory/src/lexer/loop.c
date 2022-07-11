/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 08:35:06 by steh              #+#    #+#             */
/*   Updated: 2022/07/11 17:41:28 by steh             ###   ########.fr       */
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
		init(&shell);
		if (read_cmd(&shell) == -1)
			break ;
		parse_cmd(&shell);
		print_command(&shell);
		exec_cmd(&shell);
	}
	do_exit(&shell);
}

int	read_cmd(t_shell *shell)
{
	shell->cmdline = readline("test> ");
	if (shell->cmdline == NULL)
		return (-1);
	add_history(shell->cmdline);
	disable_veof(true);
	return (0);
}