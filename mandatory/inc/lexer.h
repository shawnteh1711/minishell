#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <termios.h>
#include <stdbool.h>
#include "libft.h"

#define MAXARG 20
#define PIPELINE 5
#define MAXLINE 1024
#define MAXNAME 100

typedef	struct	s_shell
{
	char	avline[MAXLINE + 1];
	char	*cmdline;
	char	*avptr;
	char	*lineptr;
	int		append;
	int		heredoc;
	char	infile[MAXNAME];
	char	outfile[MAXNAME];
	int		cmd_count;
	int		lastpid;
}	t_shell;

typedef	struct s_command
{
	char	*args[MAXARG + 1];
	int		infd;
	int		outfd;
}	t_command;


t_command	cmds[PIPELINE];

// initialize 
void	init(t_shell *shell);
void	setup(void);
void	shell_loop(void);
void	sigint_handler(int sig);
void 	disable_veof(bool ig);
void	disable_ctrl_c(void);

int		read_cmd(t_shell *shell);
// utils
void	err_exit(const char *msg);
void	print_command(t_shell *shell);
int		check(t_shell *shell, char *str);
void	getname(char *name, t_shell *shell);
void	assign_cmd(t_shell *shell);
int		get_command2(int *i, int *j, int *inword, t_shell *shell);


#endif