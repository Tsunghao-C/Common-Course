/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:33:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 12:03:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_vars *vars, int x, int y)
{
	int	i;
	double	tmp;
	double	cx;
	double	cy;

	i = 0;
	vars->zx = 0.0;
	vars->zy = 0.0; 
	cx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	cy = vars->y0 + (y - SIZE_H / 2) * vars->zoom;
	while (++i < vars->max_iter)
	{
		tmp = vars->zx * vars->zx - vars->zy * vars->zy + cx;
		vars->zy = 2 * vars->zx * vars->zy + cy;
		vars->zx = tmp;
		if (vars->zx * vars->zx + vars->zy * vars->zy >= __DBL_MAX__)
			break;
	}
	if (i == vars->max_iter)
		my_mlx_pixel_put(&vars->img, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&vars->img, x, y, get_pallete(i, vars->pal_no));
}

void	draw_julia(t_vars *vars, int x, int y)
{
	int	i;
	double	tmp;

	i = 0;
	vars->zx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	vars->zy = vars->y0 + (y - SIZE_H / 2) * vars->zoom;
	while (++i < vars->max_iter)
	{
		tmp = vars->zx;
		vars->zx = vars->zx * vars->zx - vars->zy * vars->zy + vars->cx;
		vars->zy = 2 * vars->zy * tmp + vars->cy;
		if (vars->zx * vars->zx + vars->zy * vars->zy >= __DBL_MAX__)
			break;
	}
	if (i == vars->max_iter)
		my_mlx_pixel_put(&vars->img, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&vars->img, x, y, get_pallete(i, vars->pal_no));
}

void	draw_bs(t_vars *vars, int x, int y)
{
	int	i;
	double	tmp;
	double	cx;
	double	cy;

	i = 0;
	vars->zx = 0.0;
	vars->zy = 0.0; 
	cx = vars->x0 + (x - SIZE_W / 2) * vars->zoom;
	cy = vars->y0 + (y - SIZE_H / 2) * vars->zoom;
	while (++i < vars->max_iter)
	{
		tmp = vars->zx * vars->zx - vars->zy * vars->zy + cx;
		vars->zy = fabs(2.0 * vars->zx * vars->zy) + cy;
		vars->zx = fabs(tmp);
		if (vars->zx * vars->zx + vars->zy * vars->zy >= __DBL_MAX__)
			break;
	}
	if (i == vars->max_iter)
		my_mlx_pixel_put(&vars->img, x, y, create_trgb(0, 11, 5, 0));
	else
		my_mlx_pixel_put(&vars->img, x, y, get_pallete(i, vars->pal_no));
}
