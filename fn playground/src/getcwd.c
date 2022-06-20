/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:04:33 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 15:25:07 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int main(int argc, char const *argv[])
{
	// path_max = maximum permitted size of file paths 
	// supplied via system calls
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("Cuurent working dir: %s\n", cwd);
	else
	{
		perror("getcwd() error");
		return (1);
	}
	return (0);
}