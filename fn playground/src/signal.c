/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:52:22 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 15:01:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void	sighandler(int signum)
{
	printf("Caught signal %d, coming out...\n", signum);
	exit (1);
}

int main(int argc, char const *argv[])
{
	// ctrl + C to interupt
	signal(SIGKILL, sighandler);

	while (1)
	{
		printf("Going to sleep for a second...\n");
		sleep(1);
	}
	return (0);
}

