/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_fork_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:40:00 by steh              #+#    #+#             */
/*   Updated: 2022/06/21 22:05:35 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3 child process and 1 parent process
// 4 pipes
// process i read own i pipe, and write to i + 1 pipe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define PROCESS_NUM 3

int main(int argc, char const *argv[])
{
	int	pids[PROCESS_NUM];
	int	pipes[PROCESS_NUM + 1][2];
	int	i;

	for (i = 0; i < PROCESS_NUM + 1; i++)
	{
		if (pipe(pipes[i]) == -1)
		{
			printf("Error with creating pipe\n");
			return (1);
		}
	}

	for (i = 0; i < PROCESS_NUM; i++)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			printf("Error with creating process\n");
			return (2);
		}
		if (pids[i] == 0)
		{
			// child process
			int	j;
			for (j = 0; j < PROCESS_NUM; j++)
			{
				if (i != j)
				{
					close(pipes[j][0]);
				}
				if (i + 1 != j)
				{
					close(pipes[j][1]);
				}
			}
			int	x;
			if (read(pipes[i][0], &x, sizeof(int)) == -1)
			{
				printf("Error at reading\n");
				return (4);
			}
			printf("(%d) Got %d\n", i, x);
			x++;
			if (write(pipes[i + 1][1], &x, sizeof(int)) == -1)
			{
				printf("Error at writing\n");
				return (4);
			}
			printf("(%d) Sent %d\n", i, x);
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return (0);
		}
	}

	// main process
	printf("Input number : ");
	int	y;
	scanf("%d", &y);
	if (write(pipes[0][1], &y, sizeof(int)) == -1)
	{
		printf("Error at writing\n");
		return (4);
	}
	printf("Main process sent %d\n", y);
	if (read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1)
	{
		printf("Error at reading\n");
		return (4);
	}
	printf("The final result is %d\n", y);
	close(pipes[0][1]);
	close(pipes[PROCESS_NUM][0]);

	for (i = 0; i < PROCESS_NUM; i++)
	{
		wait(NULL);
	}
	return 0;
}

