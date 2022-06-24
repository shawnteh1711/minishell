/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:32:43 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 21:35:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0)
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("THIS SHOULD NOT PRINT ON TERMINAL!\n");
	}
	else
	{
		wait(NULL);
		printf("Success\n");
		printf("Some post processing goes here\n");
	}

	return (0);
}
