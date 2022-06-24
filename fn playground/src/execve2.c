/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:50:16 by steh              #+#    #+#             */
/*   Updated: 2022/06/19 18:56:04 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char	*binaryPath = "/bin/bash";
	char	*const argv[] = {binaryPath, "-c",
				"echo Visit $HOSTNAME:$PORT from your browser.", NULL};
	char	*const envp[] = {"HOSTNAME=www.linuxhint.com", "PORT=8080", NULL};
	if (execve(binaryPath, argv, envp) == -1)
		perror("Could not execve");
	return 0;
}
