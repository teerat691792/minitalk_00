/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:27:45 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 17:51:55 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

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

