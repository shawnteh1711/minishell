/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:11:16 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 17:42:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#define CHECK(X) ({int __val = (X); (__val == -1 ? \
				({fprintf(stderr, "ERROR (__FILE__ :%d) -- %s\n ", __LINE__, strerror(errno)); \
				exit(-1); -1;}) : __val); })

int main(int argc, char const *argv[])
{
	int	fd;
	CHECK(fd = open(argv[1], O_RDONLY));
	// handle error here

	char	c;
	while (CHECK(read(fd, &c, 1)) > 0)
	{
		fputc(c, stdout);
	}

	close(fd);
	
	return 0;
}
