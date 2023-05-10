/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:27:45 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/10 20:03:45 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

void	ft_bit(int c);

int	main(void)
{
	int	j;
	int	k;
	int	l;

	j = 106;
	k = 107;
	l = 108;
	ft_bit(j);
	ft_bit(k);
	ft_bit(l);
	ft_bit('a');
	ft_bit('b');
	ft_bit(0);
	ft_bit(1);
	ft_bit(128);
	ft_bit((1 << 1));
	ft_bit((1 << 2));
	ft_bit((1 << 3));
	ft_bit((1 << 4));
	ft_bit((1 << 5));
	ft_bit((1 << 6));
	ft_bit((1 << 7));
	return (0);
}

void	ft_bit(int c)
{
	int	count;

	printf("char =	%c\n", c);
	printf("int  =	%d\n", c);
	printf("Hex  =	%X\n", c);
	printf("bin  =	");
	count = 8;
	while (count != 0)
	{
		if (c & (1 << (count - 1)))
			printf("1");
		else
			printf("0");
		count--;
		if (count == 4)
			printf(" ");
	}
	printf("\n");
	printf("*********************\n");
}

/*

#define FLAG_BIT(n) (1 << n)

int data;  // global variable to store transmitted data

void send_message(int pid, char *message, int flag1, int flag2, int flag3) {
    strcpy((char *)&data, message);
	sleep(1);
    kill(pid, SIGUSR1);
}

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Sender: Message sent successfully\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pid> <message> <flag1> <flag2> <flag3>\n", argv[0]);
        exit(1);
    }
    int pid = atoi(argv[1]);
    char *message = argv[2];
    int flag1 = atoi(argv[3]);
    int flag2 = atoi(argv[4]);
    int flag3 = atoi(argv[5]);

    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    send_message(pid, message, flag1, flag2, flag3);
    printf("Sender: Waiting for signal confirmation\n");
    while (1) {
		sleep(1);
        pause();
    }

    return 0;
}

*/
