/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:32:52 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/25 10:00:34 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

int main(void)
{
	int		id;	
	int 	n;
	int 	i;

	
	id = fork();
	if (id == 0)
		n = 0;
	else
		n = 5;
	if (id == 0)
	{
		printf("wait id : %d\n",id);
		wait(&id);
	}
	i = n;
	while (i < n + 5)
	{
		printf("%d ",i);
		printf("from id : %d\n",id);
		fflush(stdout);
		i++;
	}
//		printf("from id : %d\n",id);


	return (0);
}
//id from newer child is always ZERO
