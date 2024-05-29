# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/05/29 16:11:50 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= ft_print_char.c \
		  ft_print_digit.c \
		  ft_printf.c \
		  ft_print_mem.c \
		  ft_print_spec.c \
		  ft_print_str.c \
		  ft_is_spec.c \
		  ft_is_left_bonus.c \
		  ft_gen_wid_pre_bonus.c \
		  ft_dgt_cnt_abs_bonus.c \
		  ft_have_zero_bonus.c \
		  ft_have_alt_bonus.c \
		  ft_have_space_bonus.c \
		  ft_have_plus_bonus.c \
		  ft_print_char_f_bonus.c \
		  ft_print_str_f_bonus.c \
		  ft_print_mem_f_bonus.c \
		  ft_print_spec_f_bonus.c \
		  ft_print_uint_f_bonus.c \
		  ft_print_sint_f_bonus.c \
		  ft_procs_flag_bonus.c \
		  ft_rm_plus_space_bonus.c \

SRCSB		=

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

HEAD		= ft_printf.h

CFLAGS		= -Wall -Wextra -Werror

ARC		= ar rcs 

CC		= cc

LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)libft.a
LIBFT_OBJS	= $(shell $(AR) t $(LIBFT))

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): libft $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	$(ARC) $(NAME) $(addprefix $(LIBFT_PATH), $(LIBFT_OBJS))

bonus: $(NAME) $(OBJSB)
	$(ARC) $(NAME) $(OBJSB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I. -I$(LIBFT_PATH)

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
