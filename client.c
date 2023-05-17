/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:25:28 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/16 17:35:40 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftminitalk.h"

char	*g_str;

int		ft_strlen(char *str);
char	*ft_strdup(char *str, int len);
int		ft_atoi(char *str);
void	ft_encoder(char *str, int pid);

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		printf("Please input following : ./client.out {PID} {strings}\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		g_str = ft_strdup(argv[2], ft_strlen(argv[2]));
		ft_encoder(g_str, pid);
	}
	free(g_str);
	return (0);
}

void	ft_encoder(char *str, int pid)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		j = 8;
		while (j != 0)
		{
			if (str[i] & (1 << (j - 1)))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
			j--;
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *str, int len)
{
	char	*tmp;
	int		i;

	if (!str || len == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_atoi(char *str)
{
	int	x;
	int	minus;
	int	n;

	n = 0;
	minus = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			minus = -1;
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
		return (0);
	x = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		x = (x * 10) + (str[n] - '0');
		n++;
	}
	return (minus * x);
}
