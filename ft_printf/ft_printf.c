/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:09:27 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 01:45:49 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_upperx(va_list args, int len)
{
	char	*str;

	str = ft_htoa(va_arg(args, unsigned int));
	str = ft_toupper_h(str);
	len += ft_putstr(str);
	free(str);
	return (len);
}

int	ft_format(char *tmp, va_list args)
{
	int		len;

	len = 0;
	if (*tmp == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*tmp == 's')
		len += ft_print_s(args, len);
	else if (*tmp == 'd' || *tmp == 'i')
		len += ft_print_d(args, len);
	else if (*tmp == 'u')
		len += ft_print_u(args, len);
	else if (*tmp == 'p')
		len += ft_print_p(args, len);
	else if (*tmp == 'x')
		len += ft_print_x(args, len);
	else if (*tmp == 'X')
		len += ft_print_upperx(args, len);
	else
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;
	char	*tmp;

	tmp = (char *)str;
	if (!tmp)
		return (0);
	va_start(args, str);
	len = 0;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			len += ft_format(tmp, args);
		}
		else
			len += ft_putchar(*tmp);
		tmp++;
	}
	va_end(args);
	return (len);
}
