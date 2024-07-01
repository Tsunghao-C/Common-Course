/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/01 17:50:55 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw_line(void *mlx, void *mlx_win, int x, int y)
{
	t_data	img;

	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	i;
	/*t_data	img;
	t_data	img2;*/

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	if (!mlx_win)
		return (0);

/*	img.img = mlx_new_image(mlx, 800, 600);
	img2.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length,
			&img2.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	my_mlx_pixel_put(&img2, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img2.img, 0, 0);*/
	i = 0;
	while (i < 200)
	{
		mlx_pixel_put(mlx, mlx_win, 100 + i, 100, 0x00FF0000);
		mlx_pixel_put(mlx, mlx_win, 100, 100 + i, 0x000000FF);
		mlx_pixel_put(mlx, mlx_win, 100 + i, 300, 0x0000FF00);
		mlx_pixel_put(mlx, mlx_win, 300, 100 + i, 0x000000FF);
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
