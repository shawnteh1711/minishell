/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcsetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:01:45 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 19:19:49 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tcsetattr = set terminal control

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	struct termios tp;
	int	fd;

	fd = open("/dev/ttp", O_RDWR);
	tcgetattr(fd, &tp);

	// can be use to reset terminal setting to original
	tcsetattr(fd, TCSANOW, &tp);
	close(fd);
	return 0;
}
