/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:49:26 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 10:23:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// compile with -lreadline
// char *readline (const char *prompt);

// Description
// Readline returns the text of the line read.
// A blank line return the empty string.
// If EOF is encountered while reading a line 
// and the line is empty, NULL is returned.
// If an EOF is read with a non-empty line, 
// it is treated as a newline.
int main(void)
{
	char *s = readline("test> ");

	if (s != NULL)
		printf("%s\n", s);
	else
		printf("NULL\n");
	return (0);
}