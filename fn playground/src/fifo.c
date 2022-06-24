/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:09 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 19:31:31 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	// myfifo can use in bash directly.
	if (mkfifo("myfifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("Could not create fifo file\n");
			return (1);
		}
	}
	printf("Opening...\n");
	// FIFO file will keep opening until receive read signal
	// in other terminal.
	int	fd =  open("myfifo1", O_WRONLY);
	if (fd == -1)
		return (3);
	int x = 97;
	printf("Opened...\n");
	if (write(fd, &x, sizeof(x)) == -1)
	{
		return (2);
	}
	printf("Written...\n");
	close(fd);
	printf("Closed...\n");
	return (0);
}
