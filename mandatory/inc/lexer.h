#ifndef LEXER_H
# define LEXER_H

#include <stdio.h>

typedef	struct	s_shell
{
	char	*line;
}	t_shell;

int		read_cmd(t_shell *shell);

#endif