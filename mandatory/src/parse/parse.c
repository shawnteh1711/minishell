/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/07 21:18:44 by steh             ###   ########.fr       */
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

int	get_command(int i, t_shell *shell)
{
	char	*lineptr;
	int		j;

	i = 0;
	j = 0;
	lineptr = shell->line;
	// avptr = shell->line;
	// printf("%s\n", shell->line);
	while (*lineptr != '\0')
	{
		while (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;
		if (*lineptr == '\n' || *lineptr== '\0')
			break ;
		
		cmd.args[j] = shell->avptr;
		while (*lineptr != '\0'
				&& *lineptr != ' '
				&& *lineptr != '\t'
				&& *lineptr != '>'
				&& *lineptr != '<'
				&& *lineptr != '|'
				&& *lineptr != '&'
				&& *lineptr != '\n')
		{
			*shell->avptr++ = *lineptr++;
		}
		*shell->avptr++ = '\0';
		// if (*lineptr == ' ' || *lineptr == '\t')
		// {
		// 	j++;
		// 	break ;
		// }
		printf("cmd[i].args[j]: %s\n", cmd.args[j]);
		j++;
			
	}
	return (0);
}

int	parse_cmd(t_shell *shell)
{
	get_command(0, shell);
	return (0);
}

int	exec_cmd(t_shell *shell)
{

	(void)shell;
	pid_t	pid = fork();
	if (pid == -1)
		err_exit("fork");
	if (pid == 0)
		execvp(cmd.args[0], cmd.args);
	wait(NULL);
	// execve();
	return (0);
}
