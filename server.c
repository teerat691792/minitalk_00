/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 15:30:53 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

int sig_svr = 10;

void ft_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("handler \n");
	usleep(500000);
}

int main(void)
{
	int		pid;
	struct	sigaction sa;

	sa.sa_handler = &ft_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	printf("server PID : %d\n",pid);

//	signal(SIGUSR1, &ft_handler);
	sleep(1);

	while (1)
		pause();

	printf("signal recieved\n");
	return (0);
}

/*

#include "libftminitalk.h"

int main(void)
{
		pid_t	pid;

		pid = getpid();
		ft_printf("		server PID = %d\n",pid);
		return (0);
}

*/
