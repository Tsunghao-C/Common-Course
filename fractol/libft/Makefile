# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 10:05:55 by tsuchen           #+#    #+#              #
#    Updated: 2024/07/05 10:20:15 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_LIBC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_atoi.c ft_calloc.c ft_strdup.c ft_strcmp.c ft_atof.c

SRCS_ARRAY	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_split_quote.c

SRCS_LIST	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS_PRINTF	= ft_print_char.c ft_print_digit.c ft_printf.c ft_print_mem.c \
		  ft_print_spec.c ft_print_str.c ft_is_spec.c ft_is_left_bonus.c \
		  ft_gen_wid_pre_bonus.c ft_dgt_cnt_abs_bonus.c ft_have_zero_bonus.c \
		  ft_have_alt_bonus.c ft_have_space_bonus.c ft_have_plus_bonus.c \
		  ft_print_char_f_bonus.c ft_print_str_f_bonus.c ft_print_mem_f_bonus.c \
		  ft_print_spec_f_bonus.c ft_print_uint_f_bonus.c ft_print_sint_f_bonus.c \
		  ft_print_sign_bonus.c ft_print_alt_bonus.c ft_procs_flag_bonus.c \
		  ft_rm_plus_space_bonus.c ft_rm_alt_bonus.c

SRCS_GNL	= get_next_line_bonus.c get_next_line_utils_bonus.c

LIBC_PATH	= srcs/libc/
ARRAY_PATH	= srcs/array/
LIST_PATH	= srcs/list/
PRINTF_PATH	= srcs/ft_printf/
GNL_PATH	= srcs/gnl/

SRCS		= $(addprefix $(LIBC_PATH), $(SRCS_LIBC)) \
		  $(addprefix $(ARRAY_PATH), $(SRCS_ARRAY)) \
		  $(addprefix $(LIST_PATH), $(SRCS_LIST)) \
		  $(addprefix $(PRINTF_PATH), $(SRCS_PRINTF)) \
		  $(addprefix $(GNL_PATH), $(SRCS_GNL))

OBJS		= $(SRCS:.c=.o)

HEAD		= includes/

CFLAGS		= -Wall -Wextra -Werror

ARC		= ar rcs

CC		= cc

all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

bonus: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEAD)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
