/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:33:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/04 19:40:21 by tsuchen          ###   ########.fr       */
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
		my_mlx_pixel_put(&vars->img, x, y, create_trgb(0, 0, 0, 0));
	else
		//my_mlx_pixel_put(&vars->img, x, y, add_shade((1.0 / log10(i)), create_trgb(0, 255, 255, 255)));
		my_mlx_pixel_put(&vars->img, x, y, create_trgb(0, 255, 255, 255) / (i % 255));
}

void	draw_julia(t_vars *vars, int x, int y)
{
	(void)x;
	(void)y;
	(void)vars;
	return ;
}

void	draw_bs(t_vars *vars, int x, int y)
{
	(void)x;
	(void)y;
	(void)vars;
	return ;
}
