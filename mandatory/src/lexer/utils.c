/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:14:39 by steh              #+#    #+#             */
/*   Updated: 2022/07/10 22:01:12 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	err_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	print_command(t_shell *shell)
{
	int	i;
	int	j;

	printf("cmd_count = %d\n", shell->cmd_count);
	if (*shell->infile != '\0')
	{
		printf("infile = [%s]\n", shell->infile);
	}
	if (*shell->outfile != '\0')
	{
		printf("outfile = [%s]\n", shell->outfile);
	}
	i = 0;
	while (i < shell->cmd_count)
	{
		j = 0;
		while (cmds[i].args[j] != NULL)
		{
			printf("[%s] ", cmds[i].args[j]);
			j++;
		}
		i++;
	}
	printf("\n");
}

int	check(t_shell *shell, char *str)
{
	char	*p;

	while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
	{
		shell->cmdline++;
	}
	p = shell->cmdline;
	while (*str != '\0' && *str == *p)
	{
		str++;
		p++;
	}
	if (*str == '\0')
	{
		shell->cmdline = p;
		return (1);
	}
	return (0);
}

void	getname(char *name, t_shell *shell)
{
	while (*shell->cmdline == ' ' || *shell->cmdline == '\t')
	{
		shell->cmdline++;
	}
	while (*shell->cmdline != '\0' && *shell->cmdline != ' '
		&& *shell->cmdline != '\t' && *shell->cmdline != '>'
		&& *shell->cmdline != '<' && *shell->cmdline != '|'
		&& *shell->cmdline != '&' && *shell->cmdline != '\n')
	{
		*name++ = *shell->cmdline++;
	}
	*name++ = '\0';
}
