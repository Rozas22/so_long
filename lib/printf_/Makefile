# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 13:07:25 by ikrozas           #+#    #+#              #
#    Updated: 2024/10/28 15:26:59 by ikrozas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	=	ft_printf.c			\
		ft_putchar.c		\
		ft_printstr.c		\
		ft_printnbr.c		\
		ft_printuint.c		\
		ft_printhex.c		\
		ft_printptr.c		\

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re