/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:53:45 by steh              #+#    #+#             */
/*   Updated: 2022/06/22 18:55:27 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *getenv(const char *name)
// searches for the environment stirng pointed by name
// and returns the associated value of the string

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	printf("PATH: %s\n", getenv("PATH"));
	printf("HOME: %s\n", getenv("HOME"));
	printf("ROOT: %s\n", getenv("ROOT"));
	return 0;
}
