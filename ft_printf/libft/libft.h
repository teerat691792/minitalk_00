/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:44:04 by tkulket           #+#    #+#             */
/*   Updated: 2023/04/26 17:54:26 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
//# include <error.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

/* Mandatory */
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);

/* Extra */
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned int n);
char	*ft_address(unsigned long n);
char	*ft_toupper_h(char *str);

#endif
