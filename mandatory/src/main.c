/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:01:46 by steh              #+#    #+#             */
/*   Updated: 2022/07/12 21:44:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

int	main(int ac, char *av[], char *envp[])
{
	t_shell	shell;

	(void)ac;
	(void)av;
	shell.envp = envp;
	setup();
	shell_loop(&shell);
	return (0);
}
