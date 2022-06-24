/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_pro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:09 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 20:10:44 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int	arr[5];
	srand(time(NULL));
	int	i;
	for (i = 0; i < 5; i++)
	{
		arr[i] = rand() % 10;
		printf("Generated %d\n", arr[i]);
	}

	int	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
	
	if (write(fd, arr, sizeof(int) * 5) == -1)
		return (2);

	// read back sum from fifo_pro2
	int	fd2 = open("sum", O_RDONLY);
	if (fd2 == -1)
		return (3);

	int sum = 0;
	if (read(fd2, &sum, sizeof(int)) == -1)
		return (4);
	printf("sum: %d\n", sum);
	return (0);
}
