# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/05/21 16:36:23 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_print_char.c \
       ft_print_digit.c \
       ft_printf.c \
       ft_print_mem.c \
       ft_print_spec.c \
       ft_print_str.c \
       ft_gen_wid_pre.c \
       ft_is_spec.c \
       ft_print_digit_flag.c \
       ft_print_spec_flag.c \
       ft_procs_spec_flag.c \

SRCSB = ft_something_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

HEAD = libftprintf.h

CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs 

CC = gcc

all: $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): libft $(OBJS)
	$(LIBC) $(NAME) $(OBJS) libft/*.o

bonus: $(NAME) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(dir $(HEAD))

clean: libft-clean root-clean

libft-clean:
	$(MAKE) -C libft clean

root-clean:
	rm -f $(OBJS) $(OBJSB)

fclean: libft-fclean root-fclean

libft-fclean:
	$(MAKE) -C libft fclean

root-fclean: root-clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus libft libft-clean libft-fclean root-clean root-fclean
