/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:05:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/05 15:05:58 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_pallete(int i, int pal_no)
{
	if (pal_no == 2)
		return (get_pallete_2(i));
	else if (pal_no == 3)
		return (get_pallete_3(i));
	return (get_pallete_1(i));
}

int	get_pallete_1(int i)
{
	if (i % 8 == 0)
		return (create_trgb(0, 133, 50, 33));
	else if (i % 8 == 1)
		return (create_trgb(0, 254, 94, 65));
	else if (i % 8 == 2)
		return (create_trgb(0, 249, 144, 93));
	else if (i % 8 == 3)
		return (create_trgb(0, 243, 193, 120));
	else if (i % 8 == 4)
		return (create_trgb(0, 230, 217, 140));
	else if (i % 8 == 5)
		return (create_trgb(0, 216, 241, 160));
	else if (i % 8 == 6)
		return (create_trgb(0, 108, 205, 140));
	else
		return (create_trgb(0, 0, 168, 120));
}

int	get_pallete_2(int i)
{
	if (i % 4 == 0)
		return (create_trgb(0, 250, 112, 112));
	else if (i % 4 == 1)
		return (create_trgb(0, 254, 253, 237));
	else if (i % 4 == 2)
		return (create_trgb(0, 198, 235, 197));
	else
		return (create_trgb(0, 161, 195, 152));
}

int	get_pallete_3(int i)
{
	if (i % 5 == 0)
		return (create_trgb(0, 229, 61, 0));
	else if (i % 5 == 1)
		return (create_trgb(0, 255, 233, 0));
	else if (i % 5 == 2)
		return (create_trgb(0, 252, 255, 247));
	else if (i % 5 == 3)
		return (create_trgb(0, 33, 160, 160));
	else
		return (create_trgb(0, 4, 104, 101));
}
