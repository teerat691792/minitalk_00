/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:34 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 17:51:57 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define FLAG_BIT(n) (1 << n)

int data;  // global variable to store received data

void sig_handler(int signum) {
    if (signum == SIGUSR1) {
        char message[256];
        int flag1, flag2, flag3;
        strcpy(message, (char *)&data);
        printf("Receiver: Message received: %s, flags: %d %d %d\n", message, flag1, flag2, flag3);
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

