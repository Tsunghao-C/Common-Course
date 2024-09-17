# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 14:29:42 by tsuchen           #+#    #+#              #
#    Updated: 2024/09/17 10:01:01 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fixed

SRCS		= main.cpp Fixed.cpp

HEADERS		= Fixed.hpp

OBJS		= $(SRCS:.cpp=.o)

HEAD		= ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98

CC			= c++

H_DEPS		= $(addprefix $(HEAD), $(HEADERS))

all: $(NAME)

$(NAME): $(OBJS) $(H_DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
