/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:44:47 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 02:02:56 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

/* ft_printf */
int	ft_printf(const char *str, ...);
int	ft_format(char *tmp, va_list args);

/* Utility */
int	ft_print_s(va_list args, int len);
int	ft_print_d(va_list args, int len);
int	ft_print_u(va_list args, int len);
int	ft_print_p(va_list args, int len);
int	ft_print_x(va_list args, int len);
int	ft_print_upperx(va_list args, int len);

#endif
