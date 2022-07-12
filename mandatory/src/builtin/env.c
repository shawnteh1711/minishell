/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:57:28 by steh              #+#    #+#             */
/*   Updated: 2022/07/12 23:06:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	do_env(t_shell *shell)
{
	char	**env;
	int		i;

	i = 0;
	env = shell->envp;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

// write own setenv
void ft_setenv(const char *name, const char *value, int overwrite)
{
	(void)name;
	(void)value;
	(void)overwrite;

}

// if var name not in env, add new else update
void	do_export(t_shell *shell)
{
	(void)shell;
	char	*value = " ";

	assign_cmd(shell);
	// cmds[0].args[0] => "shawn=hi"
	// need to further split
	if (getenv(cmds[0].args[0]) == NULL) 
	{ 
		// if exists, change the value of existing variable 
		if (setenv(cmds[0].args[0], value, 1) != 0) 
			perror("setenv"); 
	} 
	else
	{ 
		// if not exists, add it to the environment list
		char str[100];
		strcpy(str, cmds[0].args[0]);
		strcat(str, "=");
		strcat(str, value);
		if (putenv(str) != 0) 
			perror("putenv"); 
	} 
}

void	do_unset(t_shell *shell)
{
	(void)shell;
	
}