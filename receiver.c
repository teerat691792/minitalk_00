/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:34 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/10 20:46:34 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

t_var g_var;

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

int	main(void)
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
	return (0);
}

/*

#define FLAG_BIT(n) (1 << n)

int data;  // global variable to store received data

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        char message[256];
        int flag1, flag2, flag3;
        strcpy(message, (char *)&data);
        printf("Receiver: Message received: %s, message);
        printf(" flags: %d %d %d\n", flag1, flag2, flag3);
        sleep(1);
		kill(getpid(), SIGUSR1);  // send confirmation signal back to sender
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

	printf("PID : %d \n",getpid());
    printf("Receiver: Waiting for message\n");
    while (1) {
		sleep(1);
        pause();
    }

    return 0;
}

*/
