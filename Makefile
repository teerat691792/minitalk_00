# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 17:52:10 by tkulket           #+#    #+#              #
#    Updated: 2023/05/08 15:46:38 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG	=	-Wall -Werror -Wextra

NAME 	= libftminitalk.a

SRC		=	ft_printf/ft_printf.c\
			ft_printf/ft_utils.c\
			ft_printf/libft/ft_strlen.c\
			ft_printf/libft/ft_putchar.c\
			ft_printf/libft/ft_itoa.c\
			ft_printf/libft/ft_utoa.c\
			ft_printf/libft/ft_htoa.c\
			ft_printf/libft/ft_address.c\
			ft_printf/libft/ft_toupper_h.c\
			ft_printf/libft/ft_putstr.c\
			server.c\
			client.c
				
OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAG) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

c:	re
	cc $(FLAG) -g client.o -L. -lftminitalk -o client.out

s:	re
	cc $(FLAG) -g server.o -L. -lftminitalk -o server.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
