/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:48:26 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 17:56:29 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// int stat(const char *path, struct stat *buf);
// function is used to list properties of a file identified by path. 
// It reads all file properties and dumps to buf structure.
// The function is defined in sys/stat.h header file.

// information of stat is store in following
typedef struct s_stat 
{
	dev_t			st_dev;		/* ID of device containing file */
	ino_t			st_ino;		/* Inode number */
	mode_t			st_mode;	/* File type and mode */
	nlink_t			st_nlink;	/* Number of hard links */
	uid_t			st_uid;		/* User ID of owner */
	gid_t			st_gid;		/* Group ID of owner */
	dev_t			st_rdev;	/* Device ID (if special file) */
	off_t			st_size;	/* Total size, in bytes */
	blksize_t		st_blksize;	/* Block size for filesystem I/O */
	blkcnt_t		st_blocks;	/* Number of 512B blocks allocated */
	struct timespec st_atim;	/* Time of last access */
	struct timespec st_mtim;	/* Time of last modification */
	struct timespec st_ctim;	/* Time of last status change */
}	t_stat;

void	printFileProp(struct stat stats)
{
	struct tm	dt;

	// File permission
	printf("\n File access: ");
	if (stats.st_mode & R_OK)
		printf("read");
	if (stats.st_mode & W_OK)
		printf("write");
	if (stats.st_mode & X_OK)
		printf("execute");
	printf("\nFile size: %lld", stats.st_size);

	dt = *(gmtime(&stats.st_ctime));
	printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday,
			dt.tm_mon, dt.tm_year + 1900,
			dt.tm_hour, dt.tm_min, dt.tm_sec);
	dt = *(gmtime(&stats.st_mtime));
	printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday,
			dt.tm_mon, dt.tm_year + 1900, 
			dt.tm_hour, dt.tm_min, dt.tm_sec);
}

int main(void)
{
	char		path[100];
	struct stat	stats;

	printf("Enter source file path: ");
	scanf("%s", path);

	if (stat(path, &stats) == 0)
		printFileProp(stats);
	else
	{
		printf("Unable to get file properties.\n");
		printf("Please check whether '%s' file exists.\n", path);
	}
	return (0);
}
