/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcgetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:10:59 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 19:19:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


// In canonical mode input processing, 
// terminal input is processed in units of lines. 
// A line is delimited by a newline character (NL), 
// an end-of-file character (EOF), 
// or an end-of-line (EOL) character. 

//In non-canonical mode input processing, 
// input bytes are not assembled into lines, 
// and erase and kill processing does not occur. 
int main()
{
	struct termios attr;

	if(tcgetattr(fileno(stdin), &attr) != 0) {
		perror("tcgetattr");
		exit(1);
	}

	printf("c_lflag: %ld\n", attr.c_lflag);
	printf("c_oflag: %ld\n", attr.c_oflag);
	printf("c_iflag: %ld\n", attr.c_iflag);

	if(attr.c_lflag & ECHO)
		printf("echo is on, ");
	else
		printf("echo is off, ");

	if(attr.c_lflag & ICANON)
		printf("canonical mode is on\n\n");
	else
		printf("canonical mode is off\n\n");

	printf("VEOF character: %d\n",   attr.c_cc[VEOF]);
	printf("VEOL character: %d\n",   attr.c_cc[VEOL]);
	printf("VERASE character: %d\n", attr.c_cc[VERASE]);
	printf("VKILL character: %d\n",  attr.c_cc[VKILL]);

	return 0;
}