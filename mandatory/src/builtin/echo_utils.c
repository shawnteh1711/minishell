/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:23:44 by steh              #+#    #+#             */
/*   Updated: 2022/07/17 01:02:23 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"
#include "lexer.h"
#include "builtin.h"
#include "execute.h"

void	dollar(t_shell *shell, char *line, int *i, int *j)
{
	char	*ret;
	char	s[10];
	int		k;

	if (line[*i] == '$')
	{
		*j = *i + 1;
	}
	while (line[*j] != '\0')
	{
		(*j)++;
	}
	ft_memset(s, 0, sizeof(s));
	k = 0;
	(*i)++;
	while ((*i) < (*j))
	{
		s[k] = line[*i];
		k++;
		(*i)++;
	}
	s[k] = '\0';
	ret = ft_getenv(shell, s);
	if (ret != NULL)
		printf("%s", ret);
	else
		perror("getenv dollar");
}

void	dollar2(t_shell *shell, char *line, int *i, int *j)
{
	char	*ret;
	char	s[10];
	int		k;

	if (line[*j] == '$')
	{
		(*i)++;
		(*j)++;
	}
	while (line[*j] != '\"')
	{
		(*j)++;
	}
	ft_memset(s, 0, sizeof(s));
	k = 0;
	(*i)++;
	while ((*i) < (*j))
	{
		s[k] = line[*i];
		k++;
		(*i)++;
	}
	s[k] = '\0';
	ret = ft_getenv(shell, s);
	if (ret != NULL)
		printf("%s", ret);
	else
		perror("getenv dollar");
}