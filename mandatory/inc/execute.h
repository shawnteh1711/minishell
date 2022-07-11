#ifndef EXECUTE_H
# define EXECUTE_H

#include "parse.h"
#include <fcntl.h>
#include <limits.h>

int		exec_cmd(t_shell *shell);
int		exec_disk_cmd(t_shell *shell);
void	forkexec(t_shell *shell, int i);

#endif