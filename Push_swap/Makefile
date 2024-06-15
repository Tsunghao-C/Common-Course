# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/06/15 17:04:20 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap.a

SRCS 		= main.c \
		  ft_arg_check.c \


SRCSB		=

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

HEAD		= push_swap.h

CFLAGS		= -Wall -Wextra -Werror

ARC		= ar rcs 

CC		= cc

AR		= ar
AWK		= awk

LIBFT_PATH	= libft/
LIBFT_H_PATH	= libft/includes/
LIBFT		= $(LIBFT_PATH)libft.a
LIBFT_OBJS	= $(shell $(AR) t $(LIBFT) | $(AWK) '$$0 != "__.SYMDEF SORTED"')  

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): libft $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	$(ARC) $(NAME) $(addprefix $(LIBFT_PATH), $(LIBFT_OBJS))

bonus: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I. -I$(LIBFT_H_PATH)

clean: libft-clean root-clean

libft-clean:
	$(MAKE) -C $(LIBFT_PATH) clean

root-clean:
	rm -f $(OBJS) $(OBJSB)

fclean: libft-fclean root-fclean

libft-fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean

root-fclean: root-clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus libft libft-clean libft-fclean root-clean root-fclean
