/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttyslot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:17:23 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 18:23:08 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//  ttyslot - find the slot of the current user's terminal in some file /etc/ttys
int main(int argc, char const *argv[])
{
	int	slot = ttyslot();
	printf("This program is running on tty %d\n", slot);
	return 0;
}
