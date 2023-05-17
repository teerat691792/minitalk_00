/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:34 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/16 14:15:49 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

t_var g_var;

void ft_showbit(int c);
int	ft_power(int num,int p);
void	ft_interpret(void);
void	ft_receive(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	int			pid;
	struct	sigaction	sig;
	
	sig.sa_sigaction = ft_receive;
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	printf("receiver PID : %d\n", pid);
//	sleep(1);
	while (1)
		pause();
	return (0);
}

void	ft_receive(int signum, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (signum == SIGUSR1)
	{
//		printf("1 ");
		g_var.c = g_var.c | 1;
//		printf("interval g_var.c  =	%d	", g_var.c);
//		ft_showbit(g_var.c);
//		printf("\n");
	}
	else if (signum == SIGUSR2)
	{
//		printf("0 ");
		g_var.c = g_var.c | 0;
//		printf("interval g_var.c  =	%d	", g_var.c);
//		ft_showbit(g_var.c);
//		printf("\n");
	}
	g_var.count++;
	if (g_var.count == 8)
	{
//		printf("\n");
//		printf("g_var.c int  = %d\n", g_var.c);
//		printf("g_var.c char = %c\n", g_var.c);
		write(1,&g_var.c,1);
		g_var.count = 0;
		g_var.c &= 0;
//		printf("\n");
//		printf("receiver PID : %d\n", getpid());
	}
	else
		g_var.c = g_var.c << 1;
	usleep(100);
}

void	ft_interpret(void)
{
	char	*j;
//	char	*k;
//	char	*l;
	int		count;
//	int		bit[8];

	j = strdup("01101010");
//	k = strdup("01101011");
//	l = strdup("01101110");
	printf("j = %s\n",j);
	count = 0;
	printf("%d \n",'1');
	printf("%d \n", ft_power(2, 7));
	ft_showbit('j');
	printf("\n");
	while (count < 7)
	{
		if (j[count] == '1')
		{
			printf("1 ");
			g_var.c = g_var.c | 1;
			printf("interval g_var.c  =	%d	", g_var.c);
			g_var.c = g_var.c << 1;
			ft_showbit(g_var.c);
			printf("\n");
		}
		else
		{
			printf("0 ");
			g_var.c = g_var.c | 0;
			printf("interval g_var.c  =	%d	", g_var.c);
			g_var.c = g_var.c << 1;
			ft_showbit(g_var.c);
			printf("\n");
		}
		count++;
	}
	printf("\n");
	printf("g_var.c int  = %d\n", g_var.c);
	printf("g_var.c char = %c\n", g_var.c);
	printf("\n");
	free(j);
//	free(k);
//	free(l);
}

void ft_showbit(int c)
{
	int	count = 8;
	while (count != 0)
	{
		if (c & (1 << (count -1)))
			printf("1");
		else
			printf("0");
		count--;
		if (count == 4)
			printf(" ");
	}
	
}

int	ft_power(int num,int p)
{
	int base;

	if (p == 0)
		return (1);
	if (p == 1)
		return (num);
	base  = num;
	while (p > 1)
	{
		num = num * base;
		p--;
	}
	return (num);
}
