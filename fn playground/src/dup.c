/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:03:49 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 19:20:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dup() system call creates a copy of a file descriptor
// it uses the lowest-numbered unused descriptor for the 
// new descriptor. Both open same file description and this
// share file offset and file status flags


# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>


// int dup(int oldfd)
int main(int argc, char const *argv[])
{
	int file_desc = open("dup.txt", O_WRONLY);

	if (file_desc < 0)
		printf("Error opening the file\n");
	
	int copy_desc = dup(file_desc);

	write(copy_desc, "copy output form copy_desc\n", 50);
	write(file_desc, "copy output from file_desc\n", 50);
	return 0;
}
