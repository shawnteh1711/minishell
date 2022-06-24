/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:05:27 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 22:14:55 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>


// if 2 fork()
// 2 ^ 2 total = 4 process
// Parent
// ___________
// |id 1 = x |
// |id 2 = z |
// -----------  --------
//		|				|
// Process x			Process z
// ___________			___________
// |id 1 = 0 |			|id 1 = x |
// |id 2 = y |			|id 2 = 0 |
// -----------			-----------	
//		|
// Process y
// ___________
// |id 1 = 0 |
// |id 2 = 0 |
// -----------
int main(int argc, char const *argv[])
{
	int	id1 = fork();
	int	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("Process y\n");
		else
			printf("Process x\n");
	}
	else
	{
		if (id2 == 0)
			printf("Process z\n");
		else
			printf("Parent process\n");
	}
	while(wait(NULL) != -1 || errno != ECHILD)
	{
		printf("Waited for a child to finish\n");
	};
	return 0;
}

