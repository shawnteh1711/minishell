/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:40:01 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 11:43:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


// allow the prompt to go back to previous command
// void add_history (const char *string)
int main(int argc, char const *argv[])
{
	char *s;
	int i;

	while ((s = readline("test> ")))
	{
		printf("%s\n", s);
		add_history(s);
	}
	return (0);
}
