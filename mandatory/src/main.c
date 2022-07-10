/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:01:46 by steh              #+#    #+#             */
/*   Updated: 2022/07/09 21:07:45 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

// int	main(int ac, char *av[], char *envp[])
int	main(void)
{
	// (void)ac;
	// (void)av;
	// (void)envp;
	setup();
	shell_loop();
	return (0);
}
