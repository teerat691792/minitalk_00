/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:37:53 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 02:37:37 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse_digit_p(char *str)
{
	int		len;
	int		i;
	char	c;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
	return (str);
}

char	hex_digit_p(int v)
{
	if (v < 10)
		return ('0' + v);
	else
		return ('a' + (v - 10));
}

char	*dec_to_hex_recursive_p(unsigned long dec, int index, char *hex)
{
	int	remainder;

	if (dec == 0)
	{
		hex[index] = '\0';
		return (hex);
	}
	remainder = dec % 16;
	hex[index] = hex_digit_p(remainder);
	dec_to_hex_recursive_p(dec / 16, index + 1, hex);
	return (hex);
}

size_t	ft_countdigit_p(unsigned long n)
{
	size_t	d;

	d = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		d++;
	}
	return (d);
}

char	*ft_address(unsigned long n)
{
	char	*tmp;
	size_t	d;

	d = ft_countdigit_p(n);
	tmp = malloc(sizeof(char) * (d + 1));
	if (!tmp)
		return (NULL);
	dec_to_hex_recursive_p(n, 0, tmp);
	if (d > 1)
		reverse_digit_p(tmp);
	if (n == 0)
		tmp[0] = '0';
	tmp[d] = '\0';
	return (tmp);
}
