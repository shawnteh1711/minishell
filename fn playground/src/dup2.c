/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:23:34 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 19:31:04 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dup2() is similar to dup() but the basic difference between then
// is that instrad of using the lowerts-numbered unused file descriptor,
// it uses the descriptor number specified by the user

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

// int dup2(int oldfd, int newfd)
int main(int argc, char const *argv[])
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);

	if (file_desc < 0)
		printf("Error opening the file\n");

	dup2(file_desc, 1);
	printf("this is from dup2()\n");
	return 0;
}
