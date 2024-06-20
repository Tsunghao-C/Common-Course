/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:55:06 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 19:48:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_sign(long *nbr, char *flags)
{
	int	count;

	count = 0;
	if (*nbr < 0)
	{
		count += write(STDOUT_FILENO, "-", 1);
		*nbr *= -1;
	}
	else if (ft_have_space(flags) == 1)
		count += write(STDOUT_FILENO, " ", 1);
	else
		count += write(STDOUT_FILENO, "+", 1);
	return (count);
}
