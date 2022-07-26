#ifndef PARSE_H
# define PARSE_H

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int		parse_cmd(t_shell *shell);
int		parse_cmd2(t_shell *shell, int i);
void	get_command(int i, t_shell *shell);
int		get_command2(int *i, int *j, int *inword, char *line);

#endif