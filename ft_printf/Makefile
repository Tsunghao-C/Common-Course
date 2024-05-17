# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/05/17 13:53:49 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_isalpha.c \

SRCSB = ft_something_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

HEAD = libftprintf.h

CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(dir $(HEAD))

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
