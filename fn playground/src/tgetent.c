/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgetent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:11:37 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 21:51:50 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <curses.h>
#include <term.h>
// compile using -lncurses

int main() 
{ 
	char *buffer = NULL; 
	char *type = NULL; 
	char *string = NULL; 
	buffer = malloc(1024); 
	if (tgetent(buffer, type) != 1) 
	{
		printf("tgetent() fails to get entry");
		return 1;
	} 
	printf("Number of columns : %d\n", tgetnum("co"));
	printf("Number of lines : %d\n", tgetnum("li")); /* Checking boolean information */ 
	if (tgetflag("km")) 
	{
		printf("Has meta-key (8th bit of characters)\n");
	}
	if (tgetflag("xo")) 
	{
		printf("Inserted padding after Delete\n"); 
	} 
	/* Getting a string information */ 
	string = tgetstr("im", &buffer); 
	if (string != NULL) 
	{ 
		printf("Insert mode string: '%s'\n", string); 
	} 
	// free(buffer);
	return 0; 
	
}