/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:01:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 15:06:25 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
