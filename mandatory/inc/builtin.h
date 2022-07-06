#ifndef BUILTIN_H
# define BUILTIN_H

typedef	void	(*cmd_handler)(void);

typedef	struct s_builtin
{
	char		*name;
	cmd_handler	handler;
}	t_builtin;

#endif