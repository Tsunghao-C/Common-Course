/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:50:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/03 18:28:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <math.h>
# include <complex.h>
# include "mlx.h"
# define OUT STDOUT_FILENO
# define IN STDIN_FILENO
# define ERR STDERR_FILENO
# define KEY_PRESS 2
# define CLOSE_BUTTON 17
# define F1 "Mandelbrot"
# define F2 "Julia"
# define F3 "Burning_Ship"
# define WIN_SIZE 1080
# define P_NAME "fractol"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;
	int	model;
	t_data	img;
}	t_vars;

/* Error utils */
void	ft_err1_args(void);
void	ft_err2_mlx(char *str);
int		ft_isfractol(char *str);
/* mlx utils - colors */
int		create_trgb(int t, int r, int g, int b);
int		get_color(int trgb, char index);
int		add_shade(double factor, int color);
int		get_opposite(int color);
/* mlx utils - event & image */
int		on_destroy(t_vars *vars);
int		mlx_closeb(t_vars *vars);
int		move_center(int keycode, t_vars *vars);
void	mlx_clear_img(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);




#endif
