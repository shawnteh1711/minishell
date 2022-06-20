/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:31:40 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 17:44:28 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// How to send a an array through a pipe
// 2 processess
// 1) Child process should generate random numbers and send them to parent
// 2) Parent is going to sum all the numbers and print the result
int main(int argc, char const *argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		return (2);
	}
	int	pid = fork();

	if (pid == -1)
	{
		return (1);
	}

	if (pid == 0)
	{
		close(fd[0]);
		int	n, i;
		int	arr[10];
		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		for (i = 0; i < n; i++)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) < 0)
		{
			return (4);
		}

		printf("Sent n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0)
		{
			return (3);
		}
		close(fd[1]);
	}
	else	
	{
		close(fd[1]);
		int	arr[10];
		int	n, i , sum = 0;
		if (read(fd[0], &n, sizeof(int)) < 0)
			return (5);
		printf("Received n = %d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0)
			return (6);
		printf("Received array\n");
		close(fd[0]);
		for (i = 0; i < n; i++)
		{
			sum += arr[i];
		}
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return (0);
}
