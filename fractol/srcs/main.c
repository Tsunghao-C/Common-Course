/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:53:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/03 18:28:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_vars_init(t_vars *vars, char *model)
{
	vars->x = WIN_SIZE / 2;
	vars->y = WIN_SIZE / 2;
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	vars->model = ft_isfractol(model);
}

int	show_img(t_vars *vars)
{
	mlx_clear_img(vars);
	if (vars->model == 1)
		draw_mandelbrot(vars);
	else if (vars->model == 2)
		draw_julia(vars);
	else if (vars->model == 3)
		draw_bs(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2 || !ft_isfractol(av[1]))
		ft_err1_args();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_err2_mlx(av[1]);
	vars.win = mlx_new_window(vars.mlx, WIN_SIZE, WIN_SIZE, av[1]);
	ft_vars_init(&vars, av[1]);
	mlx_loop_hook(vars.mlx, show_img, &vars);
	mlx_hook(vars.win, KEY_PRESS, 1L<<0, move_center, &vars);
	mlx_hook(vars.win, CLOSE_BUTTON, 1L<<2, mlx_closeb, &vars);
	mlx_loop(vars.mlx);
	on_destroy(&vars);
	return (0);
}
