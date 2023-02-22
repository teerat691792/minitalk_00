/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:34:45 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 01:40:53 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_s(va_list args, int len)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		len += ft_putstr("(null)");
	len += ft_putstr(str);
	return (len);
}

int	ft_print_d(va_list args, int len)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	len += ft_putstr(str);
	free (str);
	return (len);
}

int	ft_print_u(va_list args, int len)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	len += ft_putstr(str);
	free(str);
	return (len);
}

int	ft_print_p(va_list args, int len)
{
	char	*str;

	str = ft_address(va_arg(args, unsigned long));
	len += ft_putstr("0x");
	len += ft_putstr(str);
	free (str);
	return (len);
}

int	ft_print_x(va_list args, int len)
{
	char	*str;

	str = ft_htoa(va_arg(args, unsigned int));
	len += ft_putstr(str);
	free(str);
	return (len);
}
