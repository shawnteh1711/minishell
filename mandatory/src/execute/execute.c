/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:34 by steh              #+#    #+#             */
/*   Updated: 2022/07/10 20:25:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	exec_cmd(t_shell *shell)
{
	(void)shell;
	char	*path = cmds[0].args[0];
	char	*argv[] = {path, NULL};
	char	*envp[] = {getenv("PATH"), NULL};

	pid_t	pid = fork();
	if (pid == -1)
		err_exit("fork");
	if (pid == 0)
	{
		// execvp(cmds[0].args[0], cmds[0].args);
		// execve(cmds[0].args[0], cmds[0].args, envp);
		// need to get PATH from env
		execve(cmds[0].args[0], argv, envp);
	}
	wait(NULL);
	return (0);
}