# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 16:51:02 by tsuchen           #+#    #+#              #
#    Updated: 2024/05/10 11:27:28 by tsuchen          ###   ########.fr        #
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

SRCS_2 = ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstadd_back.c \
	 ft_lstdelone.c \
	 ft_lstclear.c \
	 ft_lstiter.c \
	 ft_lstmap.c \

OBJS = $(SRCS:.c=.o)

OBJS_2 = $(SRCS_2:.c=.o)

HEAD = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS) $(OBJS_2)
	ar rc $(NAME) $(OBJS) $(OBJS_2)
	ranlib $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(dir $(HEAD))

clean:
	rm -f $(OBJS) $(OBJS_2)

fclean: clean
	rm -f $(NAME)

re: fclean all
