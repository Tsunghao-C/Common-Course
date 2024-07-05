# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:53:44 by tsuchen           #+#    #+#              #
#    Updated: 2024/07/05 15:12:14 by tsuchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol


SRCS_F		= main.c ft_err_utils.c ft_mlx_utils.c ft_draw_fractol.c \
		  ft_color_utils.c ft_palette.c

F_PATH		= srcs/

SRCS		= $(addprefix $(F_PATH), $(SRCS_F))

SRCSB		=

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

HEAD		= includes/

CFLAGS		= -Wall -Wextra -Werror

CC		= cc

LIBFT_PATH	= libft/
LIBFT_H_PATH	= libft/includes/
LIBFT		= $(LIBFT_PATH)libft.a

MLX		= mlx_linux

MLXFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -I$(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)

bonus:  $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEAD) -I$(LIBFT_H_PATH) -I$(MLX) -c $< -o $@

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
