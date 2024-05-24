# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:54:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/05/24 15:31:39 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \

SRCS_2 = ft_lstnew_bonus.c \
	 ft_lstadd_front_bonus.c \
	 ft_lstsize_bonus.c \
	 ft_lstlast_bonus.c \
	 ft_lstadd_back_bonus.c \
	 ft_lstdelone_bonus.c \
	 ft_lstclear_bonus.c \
	 ft_lstiter_bonus.c \
	 ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_2 = $(SRCS_2:.c=.o)

HEAD = libft.h

CFLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_2)
	$(LIBC) $(NAME) $(OBJS_2)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(dir $(HEAD))

clean:
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
