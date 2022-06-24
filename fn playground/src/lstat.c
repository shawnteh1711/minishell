/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:47:11 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 18:12:55 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int lstat(const char *path name, struct stat *statv)
// lstat() is identical to stat(), except that if pathname is a
// symbolic link, then it returns information about the link itself,
// not the file that the link refers to.

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char **argv)
{
	struct stat fileStat;
	if(argc != 2)
		return 1;

	if(lstat(argv[1],&fileStat) < 0)
		return 1;

	printf("Information for %s\n",argv[1]);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
	printf("Number of Links: \t%d\n",fileStat.st_nlink);
	printf("File inode: \t\t%llu\n",fileStat.st_ino);

	printf("File Permissions: \t");
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
 
	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
	

	// The naming is historic ... dating back to the very earliest days of UNIX. 
	// The "S" is for STAT, the "I" for INODE (a term not really used in POSIX itself outside Rationale), 
	// the "R" for READ and the "USR" for USER.
	// an inode is a data structure containing all the meta-data for the file 
	// much of which is what is read by the stat() call).
	return (0);
}