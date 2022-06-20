/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:19:52 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 17:33:47 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int	pid1;
	int	pid2;

	pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error creating process\n");
		return (1);
	}
	// child process
	if (pid1 == 0)
	{
		sleep(10);
		printf("Finish execution (%d)\n", getpid());
		return (0);
	}

	pid2 = fork();
	if (pid2 == -1)
	{
		printf("Error creating process\n");
		return (1);
	}
	// child process return first as only sleep 1
	if (pid2 == 0)
	{
		sleep(1);
		printf("Finish execution (%d)\n", getpid());
		return (0);
	}
	
	int pid1_res = waitpid(pid1, NULL, 0);
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, 0);
	printf("Waited for %d\n", pid2_res);
	// wait(NULL);
	// wait(NULL);
	return 0;
}
