/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clear_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:25:10 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 11:49:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// void	rl_clear_history(void)
int main(int argc, char const *argv[])
{
	char *s;
	int i;

	i = 0;
	
	while ((s = readline("test> ")))
	{
		printf("%s\n", s);
		add_history(s);
		i++;
		if (i > 3)
		{
			printf("clear history from now onward\n");
			clear_history();
		}
	}
	return (0);
}
