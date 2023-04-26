/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:28:34 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 15:28:37 by tkulket          ###   ########.fr       */
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
        flag1 = (data >> 0) & 1;
        flag2 = (data >> 1) & 1;
        flag3 = (data >> 2) & 1;
        printf("Receiver: Message received: %s, flags: %d %d %d\n", message, flag1, flag2, flag3);
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

    printf("Receiver: Waiting for message\n");
    while (1) {
        pause();
    }

    return 0;
}

