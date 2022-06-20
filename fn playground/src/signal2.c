/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:58:08 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 23:12:40 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}
void	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}

int main(int argc, char const *argv[])
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);

	// signal(SIGCONT, &handle_sigcont);

	int	x;

	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	// press Ctrl + Z to pause program (SIGTSTP) to background
	// press fg<pid> to bring process to foreground (SIGCONT) 
	return (0);
}
