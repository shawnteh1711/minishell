/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_on_new_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:25:10 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 12:55:45 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


void	handle_signals(int signo)
{
	if (signo == SIGINT)
	{
		printf("You pressed Ctrl+C\n");	
	}
}
int main(int argc, char const *argv[])
{
	char *s;

	while ((s = readline("test> ")))
	{
		// if (signal(SIGINT, handle_signals) == SIG_ERR)
		// 	printf("failed to register intersuprs with kernal");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return (0);
}
