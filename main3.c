/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:43:07 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 09:14:54 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

int	main(void)
{
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		printf("fork error\n");
		return (1);
	}

	if (pid == 0)
	{
		while (1)
		{
			printf("textttttttttttttttt\n");
			usleep(200000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		sleep(1);	
		kill(pid, SIGCONT);
		sleep(1);	
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
