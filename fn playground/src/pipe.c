/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:17:08 by steh              #+#    #+#             */
/*   Updated: 2022/06/21 19:49:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// program stdout -> pipe -> stdin of program
// stimulate ping -c 5 google.com | grep round-trip

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		// child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	int pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{
		// child process 1 (ping)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "round-trip", NULL);
	}
	// close main process fd
	close(fd[0]);
	close(fd[1]);

	// wait process to finish
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
