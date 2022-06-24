/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:40:31 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 22:48:42 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// file descriptor		file
// 0					STDIN
// 1					STDOUT
// 2					STDERR
// 3					pingResult.txt
// after dup()
// 4					pingResult.txt

// use dup2() to point pingResult to fd 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0)
	{
		// child process
		int	file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (3);
		printf("The fd to pingResults: %d\n", file);

		int file2 = dup2(file, STDOUT_FILENO);
		printf("The duplicated fd: %d\n", file2);
		close(file);
			
		int	err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute!\n");
			return (2);
		}
	}
	else
	{
		int	wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int	statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success!\n");
			else
				printf("Failure!\n");
		}
		printf("Some post processing goes here\n");
	}

	return (0);
}
