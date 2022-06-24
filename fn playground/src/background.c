/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:58:08 by steh              #+#    #+#             */
/*   Updated: 2022/06/20 23:03:39 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int	x;

	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	// press Ctrl + Z to pause program (SIGTSTP) to background
	// press fg<pid> to bring process to foreground (SIGCONT) 
	return (0);
}
