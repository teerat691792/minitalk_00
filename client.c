/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:25:28 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 15:25:44 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

int sig_clt = 5;

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 2)
	{
		printf("error[1] : argc input error\n");
		return (1);
	}
	else
	{
		pid = atoi(argv[1]);
		kill(pid, SIGUSR1);
	}

	return (0);
}

/*

#include "libftminitalk.h"

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
