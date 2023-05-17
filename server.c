/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/16 17:34:37 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

t_var	g_var;

void	ft_decoder(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_decoder;
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

void	ft_decoder(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signum == SIGUSR1)
		g_var.c = g_var.c | 1;
	else if (signum == SIGUSR2)
		g_var.c = g_var.c | 0;
	g_var.count++;
	if (g_var.count == 8)
	{
		write(1, &g_var.c, 1);
		g_var.count = 0;
		g_var.c = g_var.c & 0;
	}
	else
		g_var.c = g_var.c << 1;
}
