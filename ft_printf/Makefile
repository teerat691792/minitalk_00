# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 20:03:31 by tkulket           #+#    #+#              #
#    Updated: 2023/02/04 02:37:56 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

SRC		=		ft_printf.c\
				ft_utils.c\
				libft/ft_strlen.c\
				libft/ft_putchar.c\
				libft/ft_itoa.c\
				libft/ft_utoa.c\
				libft/ft_htoa.c\
				libft/ft_address.c\
				libft/ft_toupper_h.c\
				libft/ft_putstr.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
		gcc $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
