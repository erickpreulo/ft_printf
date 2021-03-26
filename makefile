# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 18:12:13 by egomes            #+#    #+#              #
#    Updated: 2021/03/26 13:15:04 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RANLIB = ranlib

HEADERS = ft_printf.h

SRC = ft_printf.c ft_putchar.c ft_strlen.c ft_print_arg.c ft_putnbr.c

.c.o:
			$(CC)  $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRC)
		@$(AR) $(NAME) $(OBJ)
		@$(RANLIB) $(NAME)
all:		$(NAME)

test:	re
		@$(CC) $(CFLAGS) test.c $(NAME) -fsanitize=address -g
		@./a.out test.txt

clean:
	@rm -f $(OBJ) ./a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all
