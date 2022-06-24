/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:23:45 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 15:30:04 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// chdir This command returns zero (0) on success. -1 is returned 
// on an error and errno is set appropriately.
int main(int argc, char const *argv[])
{
	char	s[100];

	printf("%s\n", getcwd(s, 100));
	// chdir("..");
	chdir("/Users/steh/Documents/steh/own piscine repo");
	printf("%s\n", getcwd(s, 100));

	if (chdir("/Users/steh/Documents/invalid") == -1)
		printf("Error\n");

	return (0);
}
