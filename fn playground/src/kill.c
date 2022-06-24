/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:19:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/21 15:33:10 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
	int pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("keep eating\n");
			usleep(50000);
		}
	}
	else
	{
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
		// wait(NULL) will block parent process 
		// until any of its children has finished. 
		// If child terminates before parent process reaches wait(NULL) 
		// then the child process turns to a zombie process until 
		// its parent waits on it and its released from memory.
		// If parent process doesn't wait for its child, 
		// and parent finishes first, 
		// then the child process becomes orphan 
		// and is assigned to init as its child. 
		// And init will wait 
		// and release the process entry in the process table.
	}
	return 0;
}
