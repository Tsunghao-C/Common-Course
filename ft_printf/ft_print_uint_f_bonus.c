/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_f_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/27 19:57:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dgt_cnt_abs(long nbr, char *base)
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

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_print_uint_f(long nbr, char *base, char *flags, char **wid_pre)
{
	int	count;
	int	dgt_cnt_abs;
	int	prt_len;
	int	wid;	

	count = 0;
	dgt_cnt_abs = ft_dgt_cnt_abs(nbr, base);
	prt_len = dgt_cnt_abs;
	if (wid_pre[1])
		prt_len = ft_max(dgt_cnt_abs, ft_atoi(wid_pre[1]));
	if (ft_is_left(flags) == 1)
	{
		while (prt_len > dgt_cnt_abs++)
			count += write(STDOUT_FILENO, "0", 1);
		count += ft_print_digit(nbr, base);
	}
	wid = 0;
	if (wid_pre[0])
		wid = ft_atoi(wid_pre[0]);
	while (wid-- > prt_len)
	{
		if (ft_have_zero(flags) == 1 && !wid_pre[1])
			count += write(STDOUT_FILENO, "0", 1);
		else
			count += write(STDOUT_FILENO, " ", 1);
	}
	if (ft_is_left(flags) == 0)
	{
		while (prt_len > dgt_cnt_abs++)
			count += write(STDOUT_FILENO, "0", 1);
		count += ft_print_digit(nbr, base);
	}
	return (count);
}
/* Note
 * 1. possible combination of flags for u: '-' '0'
 * 2. if precision is not null, the '0' flag is ignored
 */
