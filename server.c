/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/10 22:06:34 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

t_var g_var;

//ideal server : signal_01 --> bit --> hex --> char --> prints

void	ft_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signum == SIGUSR1)
	{
		g_var.c |= 1;
		g_var.c = g_var.c << 1;
		printf("%s	", &g_var.c);
		printf("sig 1 == count %d\n",g_var.count);
	}
	else if (signum == SIGUSR2)
	{
		g_var.c = g_var.c << 1;
		printf("%s	", &g_var.c);
		printf("sig 2 == count %d\n",g_var.count);
	}
	g_var.count++;
	if (g_var.count == 8)
	{
		printf("\n\n");
		write(1, &g_var.c, 1);
		printf("\nascii == %d\n",g_var.c);
		g_var.count = 0;
		g_var.c = g_var.c << 8;
		printf("\nPID =  %d\n\n",getpid());
	}
	usleep(100);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	printf("server PID : %d\n", pid);
	sleep(1);
	while (1)
		pause();
	return (0);
}
