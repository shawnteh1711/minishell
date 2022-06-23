/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:04:45 by steh              #+#    #+#             */
/*   Updated: 2022/06/23 22:31:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100

int main(int argc, char const *argv[])
{
	char	command[MAX_LEN];
	char	*args[MAX_LEN];
	int		should_run = 1;

	while (should_run)
	{
		printf("minishell>");
		fgets(command, MAX_LEN, stdin);
		char *token = strtok(command, "\n");
		int	i = 0;

		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, "\n");
			i++;
		}

		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			should_run = 0;
		}
		else
		{
			pid_t	process_id = fork();
			int		status;
			if (process_id == 0)
			{
				execvp(args[0], args);
			}
			else
			{
				waitpid(process_id, &status, WUNTRACED);
			}
		}
	}
	return (0);
}
