/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:51:09 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 18:00:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//isatty - test whether a file descriptor refers to a terminal
int main(int argc, char const *argv[])
{
	if (isatty(fileno(stdout)))
		printf("This is a terminal\n");
	else
		printf("This is not a terminal\n");
	
	if (isatty(0))
		printf("the standard input is from a terminal\n");
	else
		printf("the standard input is NOT from a terminal\n");
	if (isatty(1))
		printf("the standard output is to a terminal\n");
	else
		printf("the standard output is NOT to a terminal\n");
	return 0;
}
