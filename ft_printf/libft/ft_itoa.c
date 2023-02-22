/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 07:22:44 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 00:33:35 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertchar(char *str, int n, size_t d)
{
	if (n == INT_MIN)
	{
		str[0] = '-';
		str[1] = '2';
		ft_insertchar(str, 147483648, d);
	}
	else if (n < 0)
	{
		str[0] = '-';
		ft_insertchar(str, n * -1, d);
	}
	else if (n == 0)
		str[0] = '0';
	else if (n > 9)
	{
		ft_insertchar(str, n / 10, d - 1);
		str[d - 1] = (n % 10) + '0';
	}
	else
		str[d - 1] = (n % 10) + '0';
	return (str);
}

size_t	ft_countdigit(int n)
{
	size_t	d;

	d = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n *= -1;
		d++;
	}
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	size_t	d;

	d = ft_countdigit(n);
	if (d == 0)
		d = 1;
	tmp = malloc(sizeof(char) * (d + 1));
	if (!tmp)
		return (NULL);
	tmp = ft_insertchar(tmp, n, d);
	tmp[d] = '\0';
	return (tmp);
}
