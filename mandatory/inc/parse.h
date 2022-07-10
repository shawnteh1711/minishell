#ifndef PARSE_H
# define PARSE_H

#include <lexer.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	shell_loop(void);
int		parse_cmd(t_shell *shell);
void	get_command(int i, t_shell *shell);
void	get_command2(int i, int j, int inword, t_shell *shell);

#endif