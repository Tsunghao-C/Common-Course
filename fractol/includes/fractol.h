/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:50:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/04 19:40:45 by tsuchen          ###   ########.fr       */
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
# include "mlx.h"
# define OUT STDOUT_FILENO
# define IN STDIN_FILENO
# define ERR STDERR_FILENO
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_MOVE 6
# define CLOSE_BUTTON 17
# define F1 "Mandelbrot"
# define F2 "Julia"
# define F3 "Burning_Ship"
# define SIZE_W 960
# define SIZE_H 540
# define STEP 10.0
# define ZOOM_FACTOR 1.2
# define P_NAME "fractol"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int	model;
	int	max_iter;
	t_data	img;
	double	x0;
	double	y0;
	double	zx;
	double	zy;
	double	zoom;
}	t_vars;

/* Error utils */
void	ft_err1_args(void);
void	ft_err2_mlx(char *str);
int		ft_isfractol(char *str);
/* mlx utils - colors */
int		create_trgb(int t, int r, int g, int b);
int		get_color(int trgb, char index);
int		get_pallete_1(int i);
int		get_pallete_2(int i);
int		add_shade(double factor, int color);
int		get_opposite(int color);
int		get_color_grade(int i, int color);
/* mlx utils - event & image */
int		on_destroy(t_vars *vars);
int		mlx_closeb(t_vars *vars);
int		move_center(int keycode, t_vars *vars);
int		zoom(int button, int x, int y, t_vars *vars);
int		expose(t_vars *vars);
int		show_img(t_vars *vars);
void	mlx_clear_img(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
/* draw fractol */
void	draw_mandelbrot(t_vars *vars, int x, int y);
void	draw_julia(t_vars *vars, int x, int y, double cx, double cy);
void	draw_bs(t_vars *vars, int x, int y);
void	render(t_vars *vars);

#endif
