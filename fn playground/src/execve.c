/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:37:10 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 18:49:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// execve() is a POSIX (and UNIX systems in general) 
// function of the family of the exec*() functions that 
// replace the current process image.
// The v comes from the fact that it takes an argument argv 
// to the vector of arguments to the program 
// (the same way the main function of a C program may take it).
// The e comes from another of its arguments, envp, 
// which is similarly a vector of the environment variables 
// (key/value pairs like LANG=en_US.UTF-8).

// Execve() function is used for the execution 
// of the program that is referred to by pathname.
// int execve(const char *file, char *const argv[], char *const envp[])

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("Main program started\n");
	char* argv[] = {NULL};
	char* envp[] = {NULL};
	if (execve("./getcwd", argv, envp) == -1)
		perror("Could not execve");
	return 1;
}
