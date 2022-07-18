/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_backup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:33:08 by steh              #+#    #+#             */
/*   Updated: 2022/07/18 16:33:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

// void	do_echo(t_shell *shell)
// {
// 	int		i;
// 	int		j;
// 	int		nflag;
// 	char	*line;

// 	i = 0;
// 	nflag = 0;
// 	echo_cmd(shell);
// 	line = shell->cmdline;
// 	while (line[i] != '\0')
// 	{
// 		while (line[i] == ' ' || line[i] == '\t')
// 			i++;
// 		if (line[i] == '-' && line[i + 1] == 'n' && line[i + 2] == ' ')
// 		{
// 			nflag = 1;
// 			i += 2;
// 		}
// 		if (line[i] == '\"')
// 		{
// 			j = i + 1;
// 			while (line[j] != '\0')
// 			{
// 				if (line[j] == '\"')
// 				{
// 					i = j;
// 					break ;
// 				}
// 				if (line[j] == '$')
// 				{
// 					dollar2(shell, line, &i, &j);
// 				}
// 				else
// 					ft_putchar_fd(line[j], 1);
// 				j++;
// 			}
// 		}
// 		else if (line[i] == '\'')
// 		{
// 			j = i + 1;
// 			while (line[j] != '\0')
// 			{
// 				if (line[j] == '\'')
// 				{
// 					i = j;
// 					break ;
// 				}
// 				ft_putchar_fd(line[j], 1);
// 				j++;
// 			}
// 		}
// 		else if (line[i] == '$')
// 		{
// 			dollar(shell, line, &i, &j);
// 		}
// 		else if (line[i] != '\"' && line[i] != '\'' && line[i] != '$' && line[i] != ' ')
// 		{
// 			ft_putchar_fd(line[i], 1);
// 		}
// 		i++;
// 	}
// 	if (nflag == 0)
// 	{
// 		ft_putchar_fd('\n', 1);
// 	}
// }

void	do_echo3(t_shell *shell)
{
	int		j;
	int		k;
	int		nflag;
	char	*ret;
	char	*start;
	char	*end;
	char	*target = NULL;

	j = 0;
	nflag = 0;
	echo_cmd(shell);
	while (cmds[0].args[j] != NULL)
	{
		ret = ft_strnstr(cmds[0].args[j], "-n", 2);
		if (ret != NULL)
			nflag = 1;
		k = 0;
		
		if (cmds[0].args[j][k] == '\"')
		{
			k++;
			while (cmds[0].args[j][k] != '\"')
			{
				if (cmds[0].args[j][k] == '$' || cmds[0].args[j][k] == '\"')
				{
					if ((start = ft_strstr(cmds[0].args[j], "$")))
					{
						start += ft_strlen("$");
						if ((end = ft_strstr(start, "\"")))
						{
							target = (char *)malloc(end - start + 1);
							ft_memcpy(target, start, end - start + 1);
							target[end - start] = '\0';
						}
						ret = ft_getenv(shell, target);
						printf("%s", ret);
					}
				}
				else
					printf("%c", cmds[0].args[j][k]);
				k++;
			}
			break ;
		}
		else if (cmds[0].args[j][k] == '\'')
		{
			while (cmds[0].args[j][k] != '\'')
			{
				printf("%c", cmds[0].args[j][k]);
				k++;
			}
			break ;
		}
		else if (cmds[0].args[j][k] == '$')
		{
			if ((start = ft_strstr(cmds[0].args[j], "$")))
			{
				start += ft_strlen("$");
				ret = ft_getenv(shell, start);
				printf("%s", ret);
			}
		}
		else
			printf("%s", cmds[0].args[j]);
		j++;
	}
	if (nflag == 0)
		printf("\n");
}
