# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/08/06 14:28:15 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

NAME_B		= checker

SRCS_PS		= ft_err_utils.c ft_lst_utils.c ft_swap_commands.c \
		  ft_push_commands.c ft_rotate_commands.c ft_rrotate_commands.c \
		  ft_small_sort.c ft_sort_list.c ft_sort_utils.c \
		  ft_sort_utils1.c ft_sort_utils2.c ft_cheap_utils.c \
		  main.c

SRCS_CHECKER	= ft_err_utils.c ft_lst_utils.c ft_swap_commands.c \
		  ft_push_commands.c ft_rotate_commands.c ft_rrotate_commands.c \
		  ft_read_n_sort.c main.c

PS_PATH		= srcs/push_swap/
CHECKER_PATH	= srcs/checker/

SRCS		= $(addprefix $(PS_PATH), $(SRCS_PS))

SRCSB		= $(addprefix $(CHECKER_PATH), $(SRCS_CHECKER))

HEADERS		= checker.h push_swap.h

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

HEAD		= includes/

CFLAGS		= -Wall -Wextra -Werror

CC		= cc

H_DEPS		= $(addprefix $(HEAD), $(HEADERS))

LIBFT_PATH	= libft/
LIBFT_H_PATH	= libft/includes/
LIBFT		= $(LIBFT_PATH)libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS) $(H_DEPS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_B): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT) -o $(NAME_B)

bonus: $(NAME) $(NAME_B)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD) -I$(LIBFT_H_PATH)

clean: libft-clean root-clean

libft-clean:
	$(MAKE) -C $(LIBFT_PATH) clean

root-clean:
	rm -f $(OBJS) $(OBJSB)

fclean: libft-fclean root-fclean

libft-fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean

root-fclean: root-clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY:	all clean fclean re bonus libft libft-clean libft-fclean root-clean root-fclean
