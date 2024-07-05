/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 15:10:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
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

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 'a' || keycode == 65361)
		vars->x0 = vars->x0 - STEP * vars->zoom;
	else if (keycode == 'd' || keycode == 65363)
		vars->x0 = vars->x0 + STEP * vars->zoom;
	else if (keycode == 'w' || keycode == 65362)
		vars->y0 = vars->y0 - STEP * vars->zoom;
	else if (keycode == 's' || keycode == 65364)
		vars->y0 = vars->y0 + STEP * vars->zoom;
	else if (keycode == 61 || keycode == 65451)
		vars->max_iter += 2;
	else if (keycode == 45 || keycode == 65453)
		vars->max_iter -= 2;
	else if (keycode == 65307)
		on_destroy(vars);
	else if (keycode == 65470)
		vars->pal_no = 1;
	else if (keycode == 65471)
		vars->pal_no = 2;
	else if (keycode == 65472)
		vars->pal_no = 3;
	return (0);
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	double	fx;
	double	fy;

	fx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	fy = vars->y0 + (y - SIZE_H / 2) * vars->zoom;
	if (button == 4)
		vars->zoom /= ZOOM_FACTOR;
	else if (button == 5)
		vars->zoom *= ZOOM_FACTOR;
	vars->x0 = fx - (x - SIZE_W / 2) * vars->zoom;
	vars->y0 = fy - (y - SIZE_H / 2) * vars->zoom;
	return (0);
}

int	mlx_closeb(t_vars *vars)
{
	on_destroy(vars);
	return (0);
}
