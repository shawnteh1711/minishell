/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:17:54 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 18:40:50 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

// unlink deletes a title or name from any file system
int main(int argc, char const *argv[])
{
	int		fd;
	char	f[] = "new.txt";
	if ((fd = creat(f, S_IWUSR)) < 0)
		perror("creat() error\n");
	else
	{
		close(fd);
		if (unlink(f) != 0)
			perror("unlink() error\n");
	}
	// just unlink the text to remove it from ls
	return (0);
}
