/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:59:04 by steh              #+#    #+#             */
/*   Updated: 2022/06/21 16:14:09 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int	x = 0;

void	handle_sigusr1(int sig)
{
	if (x == 0)
		printf("\n(HINT) Multiplicaiton is repetitive addition!\n");
}

int main(int argc, char const *argv[])
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// child process
		sleep(1);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		// parent process

		struct sigaction	sa = { 0 };
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		printf("What is the result of 3 x 5: ");
		scanf("%d", &x);
		if (x == 15)
			printf("Right!");
		else
			printf("Wrong!");
		wait(NULL);
	}
	return 0;
}
