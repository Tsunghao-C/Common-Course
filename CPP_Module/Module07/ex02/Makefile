# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 14:29:42 by tsuchen           #+#    #+#              #
#    Updated: 2024/10/14 14:25:56 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array

SRCS		= main.cpp

HEADERS		= Array.hpp Array.tpp

OBJS		= $(SRCS:.cpp=.o)

HEAD		= ./

CFLAGS		= -Wall -Wextra -Werror -std=c++98

CC			= c++

H_DEPS		= $(addprefix $(HEAD), $(HEADERS))

all: $(NAME)

$(NAME): $(OBJS) $(H_DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
