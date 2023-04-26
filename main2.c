/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:01:24 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/25 14:15:28 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

int	main(void)
{
	int	id1;
	int	id2;
	
	id1 = fork();
	if (id1 != 0)
		wait(&id1);
	id2 = fork();
	if (id2 != 0)
		wait(&id2);

	printf("\n");
	printf("Fork ID_1 :	%d	// Fork ID_2 : %d\n",id1,id2);
	printf("Current ID :	%d	// Parent ID : %d \n",getpid(),getppid());

	if (id1 == 0)
		printf("child child\n");
	else
		printf("parent parent\n");
	if (id2 == 0)
		printf("child \n");
	else
		printf("parent\n");
	printf("END\n");

//	if (id1 != 0 ||id2 != 0)
//		sleep(1);
	return (0);
}
