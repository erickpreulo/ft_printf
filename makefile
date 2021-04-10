# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomes <egomes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 18:12:13 by egomes            #+#    #+#              #
#    Updated: 2021/04/09 23:39:16 by egomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c SRC/ft_putchar.c SRC/ft_strlen.c SRC/ft_putnbr.c SRC/ft_atoi.c SRC/ft_memset.c SRC/ft_newstr.c SRC/ft_memcpy.c SRC/ft_itoa.c SRC/ft_neg.c flags/ft_print_0.c flags/ft_print_space.c flags/ft_print_end_space.c flags/ft_print_dot.c flags/dot_u/dot_u1.c flags/dot_u/dot_u2.c flags/dot_u/dot_u3.c flags/dot_u/dot_u4.c flags/dot_u/dot_u5.c flags/dot_u/dot_u6.c flags/dot_u/dot_u7.c flags/dot_di/dot_d1.c flags/dot_di/dot_d2.c flags/dot_di/dot_d3.c flags/dot_di/dot_d4.c flags/dot_di/dot_d5.c flags/dot_di/dot_d6.c flags/dot_di/dot_d7.c flags/ft_print_as.c lether/ft_print_c.c lether/ft_print_s.c lether/ft_print_di.c lether/ft_print_x.c lether/ft_print_xX.c lether/ft_print_p.c lether/ft_print_u.c

NAME = libftprintf.a

INCLUD = -I .

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RANLIB = ranlib

.c.o:
			$(CC)  $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

OBJ = $(SRC:.c=.o)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@$(RANLIB) $(NAME)
			
all:		$(NAME)

test:	re
		@$(CC) $(CFLAGS) test.c $(NAME) -fsanitize=address -g
		./a.out test.txt

clean:
	@rm -f $(OBJ) ./a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all
