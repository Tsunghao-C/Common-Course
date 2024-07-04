/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:55:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/04 14:19:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* Ecoding and decoding colors */
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

/* helper functions to change color */
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

/* exit function */
int	on_destroy(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

/* Events */
int	mlx_close(int keycode, t_vars *vars)
{
	ft_printf("keycode is %d\n", keycode);
	if (keycode == 65307)
		on_destroy(vars);
	return (0);
}

int	mlx_closeb(t_vars *vars)
{
	on_destroy(vars);
	return (0);
}

int	mlx_release(int keycode, t_vars *vars)
{
	ft_printf("release %d\n", keycode);
	if (keycode == 65307)
		on_destroy(vars);
	return (0);
}

int	mlx_in(void)
{
	ft_printf("Hello!\n");
	return (0);
}

int	mlx_out(void)
{
	ft_printf("Bye!\n");
	return (0);
}

int	mlx_mo(int x, int y)
{
	if (x == y)
		ft_printf("x = %d | y = %d\n", x, y);
	return (0);
}

/* key press monitoring (but not working) */
/*void	state_init(t_state *state)
{
	state->key_pressed = 0;
	state->frame_counter = 0;
	state->warning_printed = 0;
	state->key_code = 0;
}

int	key_press(int keycode, t_state *state)
{
	if (!state->key_pressed)
	{
		state->key_pressed = 1;
		state->frame_counter = 0;
		state->warning_printed = 0;
		state->key_code = keycode;
	}
	return (0);
}

int	key_release(int keycode, t_state *state)
{
	state->key_pressed = 0;
	state->key_code -= keycode;
	return (0);
}

void	print_warning(t_state *state)
{
	if (state->key_pressed && !state->warning_printed)
	{
		if (state->frame_counter >= WARNING_THRESHOLD)
		{
			//ft_printf("Warning: consecutive key pressed on %d!!\n", state->key_code);
			state->warning_printed = 1;
		}
	}
}*/

/*int	loop_hook(t_state *state)
{
	if (state->key_pressed)
	{
		state->frame_counter++;
		print_warning(state);
	}
	return (0);
}*/

/* Loops */

int	loop_hook2(t_vars *vars)
{
	t_img	img;
	char	*path;

	path = "./xpm_files/test.xpm";
	mlx_clear_window(vars->mlx, vars->win);
	vars->counter++;
	img.img = mlx_xpm_file_to_image(vars->mlx, path, &(img.img_width), &(img.img_height));
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, (vars->counter % 600), (vars->counter % 800));
	return (0);
}

/* Loops tests 1: moveable circle */

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
	else if (keycode == 'b')
		vars->color = create_trgb(0, 0, 0, 255);
	else if (keycode == 'r')
		vars->color = create_trgb(0, 255, 0, 0);
	else if (keycode == 'g')
		vars->color = create_trgb(0, 0, 255, 0);
	else if (keycode == ' ')
		vars->color = create_trgb(0, 255, 255, 255);
	else if (keycode == 65307)
		on_destroy(vars);
	else
		ft_printf("keypress %d\n", keycode);
	return (0);
}

void	draw_circle(t_vars *vars, int r, int color)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - 2 * r;
	while (y >= x)
	{
		my_mlx_pixel_put(&vars->img, vars->x + x, vars->y + y, color);
		my_mlx_pixel_put(&vars->img, vars->x - x, vars->y + y, color);
		my_mlx_pixel_put(&vars->img, vars->x + x, vars->y - y, color);
		my_mlx_pixel_put(&vars->img, vars->x - x, vars->y - y, color);
		my_mlx_pixel_put(&vars->img, vars->x + y, vars->y + x, color);
		my_mlx_pixel_put(&vars->img, vars->x - y, vars->y + x, color);
		my_mlx_pixel_put(&vars->img, vars->x + y, vars->y - x, color);
		my_mlx_pixel_put(&vars->img, vars->x - y, vars->y - x, color);
		if (d <= 0)
			d = d + 4 * x + 6;
		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

void	draw_square(t_vars *vars, int len, int color)
{
	int	i;
	int	off_set;

	i = 0;
	off_set = len / 2;
	while (i < len)
	{
		my_mlx_pixel_put(&vars->img, vars->x - off_set + i, vars->y + off_set, color);
		my_mlx_pixel_put(&vars->img, vars->x - off_set + i, vars->y - off_set, color);
		my_mlx_pixel_put(&vars->img, vars->x + off_set, vars->y + off_set - i, color);
		my_mlx_pixel_put(&vars->img, vars->x - off_set, vars->y + off_set - i, color);
		i++;
	}
}

void	draw_line(t_vars *vars, int *start, int *end, int color)
{
	int	dx;
	int	dy;
	int	x0 = start[0];
	int	y0 = start[1];
	int	intcpt;

	dx = end[0] - start[0];
	dy = end[1] - start[1];
	if (!dx)
	{
		while (y0 != end[1])
		{
			my_mlx_pixel_put(&vars->img, x0, y0, color);
			if (dy >= 0)
				y0++;
			else
				y0--;
		}
	}
	else
	{
		intcpt = y0 - ((dy * x0 / dx));
		while (x0 != end[0] || y0 != end[1])
		{
			my_mlx_pixel_put(&vars->img, x0, y0, color);
			if (dx >= 0)
				x0 += 1;
			else
				x0 -= 1;
			y0 = (dy * x0 / dx) + intcpt;
		}
	}
}

void	draw_triangular(t_vars *vars, int ends[3][2], int color)
{
	draw_line(vars, ends[0], ends[1], color);
	draw_line(vars, ends[0], ends[2], color);
	draw_line(vars, ends[1], ends[2], color);
}

void	mlx_clear_img(t_vars *vars)
{
	ft_bzero(vars->img.addr, sizeof(int) * 800 * 800);
}

int	show_img(t_vars *vars)
{
	int	radius;
	int	ends[3][2] = {{400, 100}, {700, 700}, {100, 700}};
	//int	start[2] = {400, 100};
	//int	end[2] = {100, 700};

	radius = 100;
	mlx_clear_img(vars);
	draw_circle(vars, radius, vars->color);
	draw_square(vars, 2 * radius, vars->color);
	draw_triangular(vars, ends, vars->color);
	//draw_line(vars, start, end, color);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 800, 800, "WASD_Circle");
	vars.x = 400;
	vars.y = 400;
	vars.color = create_trgb(0, 255, 255, 255);
	vars.img.img = mlx_new_image(vars.mlx, 800, 800);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_loop_hook(vars.mlx, show_img, &vars);
	mlx_hook(vars.win, 2, 1L<<0, move_center, &vars);
	mlx_hook(vars.win, 17, 1L<<2, mlx_closeb, &vars);	//close button
	mlx_loop(vars.mlx);
	on_destroy(&vars);
	return (0);
}

/* Image test */
/*int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "image");
	vars.counter = 0;
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop_hook(vars.mlx, loop_hook2, &vars);
	mlx_loop(vars.mlx);
	return (0);
}*/
/*
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Counter");
	vars.counter = 0;
	mlx_hook(vars.win, 2, 1L<<0, mlx_close, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}*/
/*
int	main(void)
{
	t_vars	vars;
	int	i;
	int	trgb;
	int	trgb2;
	t_state	key_state;

	state_init(&key_state);
	trgb = create_trgb(0, 148, 57, 70);
	trgb2 = add_shade(0.5, trgb);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
	i = 0;
	while (i < 200)
	{
		mlx_pixel_put(vars.mlx, vars.win, 100 + i, 100, trgb);
		mlx_pixel_put(vars.mlx, vars.win, 100, 100 + i, get_opposite(trgb));
		mlx_pixel_put(vars.mlx, vars.win, 100 + i, 300, trgb2);
		mlx_pixel_put(vars.mlx, vars.win, 300, 100 + i, get_opposite(0x000000FF));
		i++;
	}
	mlx_hook(vars.win, 2, 1L<<0, key_press, &key_state);	//keyboard press
	mlx_hook(vars.win, 3, 1L<<1, key_release, &key_state);	//keyboard release
	mlx_loop_hook(vars.mlx, loop_hook, &key_state);		//Continuous to add counts if no events
	mlx_hook(vars.win, 3, 1L<<1, mlx_close, &vars);		//keyboard release for exit
	mlx_hook(vars.win, 4, 1L<<2, mlx_close, &vars);		//mouse button click for exit
	mlx_hook(vars.win, 6, 1L<<6, mlx_mo, &vars);		//mouse motion detection
	mlx_hook(vars.win, 7, 1L<<4, mlx_in, &vars);		//mouse enter window
	mlx_hook(vars.win, 8, 1L<<5, mlx_out, &vars);		//mouse leave window
	mlx_hook(vars.win, 17, 1L<<2, mlx_closeb, &vars);	//close button
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}*/
