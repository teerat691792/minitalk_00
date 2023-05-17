# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 17:52:10 by tkulket           #+#    #+#              #
#    Updated: 2023/05/17 07:46:33 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG	=	-Wall -Werror -Wextra -g

NAME 	= libftminitalk.a

SRC		=	server.c\
			client.c
				
OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	gcc $(FLAG) client.o -L. -lftminitalk -o client
	gcc $(FLAG) server.o -L. -lftminitalk -o server

c:	re
	gcc $(FLAG) client.o -L. -lftminitalk -o client

s:	re
	gcc $(FLAG) server.o -L. -lftminitalk -o server

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) client server

re: fclean all

# make prompt client and server

.PHONY : all clean fclean re s c
