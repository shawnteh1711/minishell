/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgoto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:53:07 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 22:28:56 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>

// int main(int argc, char const *argv[])
// {
// 	int	x, y;
// 	char	*term;

// 	term = getenv("TERM");
// 	if (term == NULL)
// 	{
// 		puts("TERM environment variable not set");
// 		return (1);
// 	}

// 	if (tgetent(NULL, term) <= 0)
// 	{
// 		puts("Could not access the termcap database");
// 		return (2);
// 	}

// 	x = 10;
// 	y = 10;

// 	tgoto(tgetstr("cm", NULL), x, y);
// 	tputs(tgetstr("Hello world", NULL), 1, putchar);
// 	puts(tgetstr("ve", NULL));
	
// 	return (0);
// }

#include <stdio.h>
#include <curses.h>

int main()
{
	// start curses mode
	initscr();
	// move cursor to 5, 10
	tputs(tparm(tgetstr("cm", NULL), 5, 10), 1, putchar);
	tputs("Hello World!!!\n", 1, putchar);
	addstr("Hello, world!");
	refresh();
	getch();
	endwin();

	return 0;
	
}
