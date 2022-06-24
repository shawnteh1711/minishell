#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>

typedef	void	(*cmd_handler)(void);

typedef	struct s_builtin
{
	char		*name;
	cmd_handler	handler;
}	t_builtin;


void	do_exit(void);
int		parse(void);

#endif