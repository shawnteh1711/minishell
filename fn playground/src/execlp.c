/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execlp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:22:28 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 22:31:36 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	// execlp(
	// 	"ping",
	// 	"ping",
	// 	"google.com",
	// 	NULL
	// );

	char *arr[] = {
		"ping",
		"google.com",
		NULL
	};

	char *env[] = {
		"TEST=environment variable",
		NULL
	};

	if (execve("/sbin/ping", arr, env) == -1)
		perror("Could not execve");
	
	printf("Ping finished executing\n");
	return (0);
}
