#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft.h"

#define MAXARG 20
#define PIPELINE 5
#define MAXLINE 1024
#define MAXNAME 100

typedef	struct	s_shell
{
	// char	avline[MAXLINE + 1];
	char	avline[MAXLINE + 1];
	char	*cmdline;
	char	*avptr;
	char	*lineptr;
	char	*args[MAXARG + 1];
	int		infd;
	int		outfd;
	int		append;
	// char	*infile;
	// char	*outfile;
	char	infile[MAXNAME];
	char	outfile[MAXNAME];
	int		cmd_count;
}	t_shell;

t_shell	cmds[PIPELINE];

int		read_cmd(t_shell *shell);
void	init(t_shell *shell);
void	setup(void);
void	sigint_handler(int sig);

// utils
void	err_exit(const char *msg);
void	print_command(t_shell *shell);
int		check(t_shell *shell, char *str);
void	getname(char *name, t_shell *shell);

#endif