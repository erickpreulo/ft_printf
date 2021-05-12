# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 18:12:13 by egomes            #+#    #+#              #
#    Updated: 2021/05/12 15:54:05 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c srcs/ft_putchar.c srcs/ft_strlen.c srcs/ft_putnbr.c \
		srcs/ft_atoi.c srcs/ft_memcpy.c \
		srcs/ft_itoa.c srcs/ft_neg.c flags/ft_print_0.c flags/ft_print_space.c \
		flags/ft_print_end_space.c flags/ft_print_dot.c flags/ft_print_dot_1.c \
		dot_x/dot_x1.c dot_x/dot_x2.c dot_x/dot_x3.c \
		dot_x/dot_x3_1.c dot_x/dot_x7.c dot_u/dot_u1.c \
		dot_u/dot_u2.c dot_u/dot_u3.c dot_u/dot_u3_1.c \
		dot_u/dot_u4.c dot_u/dot_u5.c dot_u/dot_u6.c \
		dot_di/dot_d1.c dot_di/dot_d2.c \
		dot_di/dot_d3.c dot_di/dot_d3_1.c dot_di/dot_d4.c \
		dot_di/dot_d5.c dot_di/dot_d6.c flags/ft_print_as_4.c \
		flags/ft_print_as.c flags/ft_print_as_1.c flags/ft_print_as_2.c \
		flags/ft_print_as_3.c lether/ft_print.c lether/ft_print_x.c \
		flags/ft_print_end_space_1.c flags/ft_print_space_1.c

NAME = libftprintf.a

INCLUD = -Iincludes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

.c.o:
			@$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			
all:		$(NAME)

test:	re
		@$(CC) test.c $(NAME) -fsanitize=address -g
		./a.out

clean:
		${shell find . -type f -name "*.o" -delete}
##		${wildcard */*.o}
##	rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
