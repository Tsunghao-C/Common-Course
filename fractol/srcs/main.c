/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:53:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 12:03:49 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_vars_init(t_vars *vars, char *model)
{
	char	*c_real;
	char	*c_imag;

	vars->x0 = 0.0;
	vars->y0 = 0.0;
	vars->cx = 0.0;
	vars->cy = 0.0;
	vars->zoom = 4.0 / SIZE_W;
	vars->max_iter = 50;
	vars->pal_no = 1;
	vars->img.img = mlx_new_image(vars->mlx, SIZE_W, SIZE_H);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_length, &vars->img.endian);
	vars->model = ft_isfractol(model);
	if (vars->model == 2)
	{
		ft_printf("Input C_real in float: ");
		c_real = get_next_line(IN);
		ft_printf("Input C_imag in float: ");
		c_imag = get_next_line(IN);
		vars->cx = ft_atof(c_real);
		vars->cy = ft_atof(c_imag);
		free(c_real);
		free(c_imag);
	}
}

int	show_img(t_vars *vars)
{
	int	x;
	int	y;

	mlx_clear_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	x = 0;
	y = 0;
	while (x < SIZE_W)
	{
		while (y < SIZE_H)
		{
			if (vars->model == 1)
				draw_mandelbrot(vars, x, y);
			else if (vars->model == 2)
				draw_julia(vars, x, y);
			else if (vars->model == 3)
				draw_bs(vars, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	expose(t_vars *vars)
{
	show_img(vars);
	return (0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2 || !ft_isfractol(av[1]))
		ft_err1_args();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_err2_mlx(av[1]);
	vars.win = mlx_new_window(vars.mlx, SIZE_W, SIZE_H, av[1]);
	ft_vars_init(&vars, av[1]);
	mlx_loop_hook(vars.mlx, show_img, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L<<0, move_center, &vars);
	mlx_hook(vars.win, MOUSE_PRESS, 1L<<2, zoom, &vars);
	mlx_hook(vars.win, CLOSE_BUTTON, 1L<<2, mlx_closeb, &vars);
	mlx_expose_hook(vars.win, expose, &vars);
	mlx_loop(vars.mlx);
	on_destroy(&vars);
	return (0);
}
