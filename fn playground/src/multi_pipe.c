/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:50:36 by steh              #+#    #+#             */
/*   Updated: 2022/06/21 20:06:59 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

// fd[3][2]
// 3 pipe
// 6 fd each process to close
// total 2 ^ 3 process =  18 fd
// Parent
// ___________
// |fd[0][1] |
// |fd[2][0] |
// -----------  --------
//						|
//		⬆⬇				⬆⬇
// Process 1			Process 2
// ___________			___________
// |fd[0][0] |			|fd[2][1] |
// |fd[1][1] |	<-		|fd[1][0] |
// -----------	->		-----------	

int main(int argc, char const *argv[])
{
	int	fd[3][2];
	int	i;

	for (i = 0; i < 3; i++)
	{
		if (pipe(fd[i]) < 0)
		{
			return (1);
		}
	}

	int	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		// child process 1
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int	x;
		if (read(fd[0][0], &x, sizeof(int)) < 0)
			return (3);
		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0)
			return (4);
		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}
	
	int	pid2 = fork();
	if (pid2 < 0)
		return (5);
	if (pid2 == 0)
	{
		// child process 2
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		int	x;
		if (read(fd[1][0], &x, sizeof(int)) < 0)
			return (6);
		x += 5;
		if (write(fd[2][1], &x, sizeof(int)) < 0)
			return (7);
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}

	// parent process
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	int	x;
	printf("Input number: ");
	scanf("%d", &x);
	if (write(fd[0][1], &x, sizeof(int)) < 0)
		return (8);
	if (read(fd[2][0], &x, sizeof(int)) < 0)
		return (9);
	printf("Result is : %d\n", x);
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
