/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_cnt_abs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:09:52 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/28 19:14:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dgt_cnt_abs(long nbr, char *base)
{
	int		count;
	long	base_len;

	count = 0;
	base_len = (long)ft_strlen(base);
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= base_len)
		count += ft_dgt_cnt_abs((nbr / base_len), base);
	count += 1;
	return (count);
}
