/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioctl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:29:28 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 18:46:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// iooctl is input and output control, which is used to talking
// to device driveers.

#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define WR_VALUE _IOW('a', 'b', int32_t*)
#define RD_VALUE _IOR('a', 'b', int32_t*)

int main()
{
	int	fileDescriptor;
	int32_t val, num;
	printf("\nOpening the Driver\n");
	fileDescriptor = open("/dev/random", O_RDWR);
	if (fileDescriptor < 0)
	{
		printf("Unabel to open device file\n");
		return (0);
	}
	printf("Enter the value that you want to send \n");
	scanf("%d", &num);
	printf("Writing the value to the drive \n");
	ioctl(fileDescriptor, WR_VALUE, (int32_t) &num);
	printf("Reading the value to the drive \n");
	ioctl(fileDescriptor, RD_VALUE, (int32_t) &val);
	printf("The value is %d\n", val);

	printf("Closing the driver\n");
	close(fileDescriptor);
	return (0);
}