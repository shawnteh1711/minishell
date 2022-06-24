/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:16 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 17:23:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int	fd;
	fd = open(argv[1], O_RDONLY);
	// handle error here
	if (fd == -1)
	{
		fprintf(stderr, "errno = %i\n", errno); // print errno
		fprintf(stderr, "msg = %s\n", strerror(errno)); // print err msg
		perror("Error");
		exit(-1);
	}


	char	c;
	while (read(fd, &c, 1) > 0)
	{
		fputc(c, stdout);
	}

	close(fd);
	
	return 0;
}
