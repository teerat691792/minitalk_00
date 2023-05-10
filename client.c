/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:25:28 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/10 21:28:37 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

char	*str;

//ideal client : argv --> hex --> bit (send)  

void	ft_compare_bit(char *str, int pid)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = strlen(str);
	while(i < len)
	{
		j = 8;
		while(j != 0)
		{
			if (str[i] & (1 << j))
			{
//				printf("SIG1	1\n");
				write(1,"1",1);
				kill(pid, SIGUSR1);
			}
			else
			{
//				printf("SIG2	0\n");
				write(1,"0",1);
				kill(pid, SIGUSR2);
			}
			usleep(400);
			j--;
		}
		i++;
	}
				write(1,"\n",1);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		printf("error[1] : argc input error\n");
		return (1);
	}
	else
	{
		pid = atoi(argv[1]);
		str = strdup(argv[2]);
		printf("str	= %s\n",str);
		printf("ascii	= %d\n",str[0]);
		ft_compare_bit(str, pid);		
	}
	free(str);
	return (0);
}

/*
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("please enter input as followeding\n");
		ft_printf("./client.out [PID] [string]\n");
		return (1);
	}
	ft_printf("PID	=	%s\n",argv[1]);
	ft_printf("str	=	%s\n",argv[2]);
	return (0);
}
*/

/*
#define FLAG_BIT(n) (1 << n)

int data;  // global variable to store transmitted data

void send_message(int pid, char *message) {
    strcpy((char *)&data, message);
    data = (data & ~FLAG_BIT(0));
    data = (data & ~FLAG_BIT(1));
    data = (data & ~FLAG_BIT(2));
    kill(pid, SIGUSR1);
}

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
		sleep(1);
        printf("Sender: Message sent successfully\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pid> <message> \n", argv[0]);
        exit(1);
    }
    int pid = atoi(argv[1]);
    char *message = argv[2];

    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    send_message(pid, message, flag1, flag2, flag3);
    printf("Sender: Waiting for signal confirmation\n");
    while (1) {
        pause();
    }

    return 0;
}
*/
