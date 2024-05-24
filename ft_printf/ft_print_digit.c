/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 15:59:38 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long nbr, char *base)
{
	int		count;
	long	base_len;

	count = 0;
	base_len = (long)ft_strlen(base);
	if (nbr < 0)
	{
		count += write(STDOUT_FILENO, "-", 1);
		nbr *= (-1);
	}
	if (nbr >= base_len)
		count += ft_print_digit((nbr / base_len), base);
	count += ft_print_char(base[(nbr % base_len)]);
	return (count);
}
