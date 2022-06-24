/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_pro2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:18:09 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 20:12:19 by steh             ###   ########.fr       */
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
	int	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (1);

	if (read(fd, arr, sizeof(int) * 5) == -1)
		return (2);
	
	int	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];
	}
	printf("Result is %d\n", sum);

	// send sum to fifo_pro.c
	int sum2 = sum;
	int	fd2 = open("sum", O_WRONLY);
	if (fd2 == -1)
		return (1);
	if (write(fd2, &sum2, sizeof(int)) == -1)
		return (2);
	return (0);
}
