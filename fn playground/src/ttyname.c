/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:07:51 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 18:10:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// The function ttyname() returns a pointer to a pathname on success. 
int main(int argc, char const *argv[])
{
	printf("This program is running on %s\n", ttyname(STDIN_FILENO));
	return 0;
}
