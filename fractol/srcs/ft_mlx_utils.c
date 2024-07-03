/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/03 18:28:04 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int trgb, char index)
{
	if (index == 't')
		return ((trgb >> 24) & 0xFF);
	else if (index == 'r')
		return ((trgb >> 16) & 0xFF);
	else if (index == 'g')
		return ((trgb >> 8) & 0xFF);
	else
		return (trgb & 0xFF);
}

int	add_shade(double factor, int color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;

	new_t = get_color(color, 't');
	new_r = get_color(color, 'r') * (1 - factor);
	new_g = get_color(color, 'g') * (1 - factor);
	new_b = get_color(color, 'b') * (1 - factor);
	return (create_trgb(new_t, new_r, new_g, new_b));
}

int	get_opposite(int color)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	new_b;

	new_t = get_color(color, 't');
	new_r = 255 - get_color(color, 'r');
	new_g = 255 - get_color(color, 'g');
	new_b = 255 - get_color(color, 'b');
	return (create_trgb(new_t, new_r, new_g, new_b));
}

int	on_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	mlx_closeb(t_vars *vars)
{
	on_destroy(vars);
	return (0);
}

int	move_center(int keycode, t_vars *vars)
{
	int	step;

	step = 10;
	if (keycode == 'a' || keycode == 65361)
		vars->x = vars->x - step;
	else if (keycode == 'd' || keycode == 65363)
		vars->x = vars->x + step;
	else if (keycode == 'w' || keycode == 65362)
		vars->y = vars->y - step;
	else if (keycode == 's' || keycode == 65364)
		vars->y = vars->y + step;
	else if (keycode == 65307)
		on_destroy(vars);
	else
		ft_printf("keypress %d\n", keycode);
	return (0);
}

void	mlx_clear_img(t_vars *vars)
{
	ft_bzero(vars->img.addr, sizeof(int) * 800 * 800);
}
