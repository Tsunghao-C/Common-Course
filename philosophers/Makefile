# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 14:29:42 by tsuchen           #+#    #+#              #
#    Updated: 2024/08/13 19:47:15 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

NAME_BONUS	= philo_bonus

SRCS_MAN	= main.c ft_atol.c phil_utils.c err_utils.c phil_activity.c time_utils.c

SRCS_BONUS	= main.c ft_atol.c phil_utils_b.c time_utils_b.c err_utils_b.c phil_activity_b.c child_utils_b.c

MAN_PATH	= srcs/mandatory/

BONUS_PATH	= srcs/bonus/

SRCS		= $(addprefix $(MAN_PATH), $(SRCS_MAN))

SRCS_B		= $(addprefix $(BONUS_PATH), $(SRCS_BONUS))

HEADERS		= philo.h

HEADERS_B	= philo_bonus.h

OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

HEAD		= includes/

CFLAGS		= -Wall -Wextra -Werror

CC		= cc

H_DEPS		= $(addprefix $(HEAD), $(HEADERS))

H_DEPS_B	= $(addprefix $(HEAD), $(HEADERS_B))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(H_DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_B) $(H_DEPS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
