/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:26:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/10 19:41:22 by tkulket          ###   ########.fr       */
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
		write(1, &g_var.c, 1);
		printf("\nsig 1 == count %d\n",g_var.count);
	}
	else if (signum == SIGUSR2)
	{
		g_var.c = g_var.c << 1;
		write(1, &g_var.c, 1);
		printf("\nsig 2 == count %d\n",g_var.count);
	}
	g_var.count++;
	if (g_var.count == 8)
	{
		printf("\n\n");
		write(1, &g_var.c, 1);
		printf("\nascii == %d\n",g_var.c);
		g_var.count = 0;
		g_var.c = g_var.c << 8;
		printf("\nPID =  %d\n",getpid());
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
//	signal(SIGUSR1, &ft_handler);
	sleep(1);
	while (1)
		pause();
	printf("signal recieved\n");
	return (0);
}

/*
#define FLAG_BIT(n) (1 << n)

int data;  // global variable to store received data

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        char message[256];
        strcpy(message, (char *)&data);
        flag1 = (data >> 0) & 1;
        flag2 = (data >> 1) & 1;
        flag3 = (data >> 2) & 1;
        printf("Receiver: Message received: %s", message);
        printf(", flags: %d %d %d\n", flag1, flag2, flag3);
		sleep(1);
        kill(getpid(), SIGUSR1);  // send confirmation signal back to sender
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }


	printf("server PID : %d\n",getpid());
    printf("Receiver: Waiting for message\n");
    while (1) {
        pause();
    }

    return 0;
}
*/
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
