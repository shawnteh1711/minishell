/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:15:47 by steh              #+#    #+#             */
/*   Updated: 2022/07/07 20:23:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

void	init(t_shell *shell)
{
	ft_memset(shell->line, 0, sizeof(shell->line));
	shell->avptr = shell->line;

}