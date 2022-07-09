#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"

#define MAXARG 20
#define PIPELINE 5
#define MAXLINE 1024

typedef	struct	s_shell
{
	char	avline[MAXLINE + 1];
	char	*avptr;
	char	*line;
	char	*args[MAXARG + 1];
	int		infd;
	int		outfd;
}	t_shell;

t_shell	cmds[PIPELINE];
t_shell	cmd;

int		read_cmd(t_shell *shell);

// utils
void	err_exit(const char *msg);

#endif