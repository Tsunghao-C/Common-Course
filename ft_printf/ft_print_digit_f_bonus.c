/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_f_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/27 16:18:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_count_abs(long nbr, char *base)
{
	int		count;
	long	base_len;

	count = 0;
	base_len = (long)ft_strlen(base);
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= base_len)
		count += ft_digit_count_abs((nbr / base_len), base);
	count += 1;
	return (count);
}

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_print_digit_f(long nbr, char *base, char *flags, char **wid_pre)
{
	int		count;
	int		dig_cnt;

	count = 0;
	dig_cnt = 0;
	return (count);
}

int	ft_print_digit_left(long nbr, char *base, int wid, int pre)
{
	int		count;
	int		dig_cnt;
	int		i;
	int		j;

	count = 0;
	dig_cnt = ft_digit_count_abs(nbr, base);
	if (nbr < 0)
		wid--;
	j = pre;
	if (dig_cnt < wid || dig_cnt < pre)
	{
		while (j-- > dig_cnt)
		{
			if (nbr < 0)
			{
				count += write(STDOUT_FILENO, "-", 1);
				nbr *= -1;
			}
			count += write(STDOUT_FILENO, "0", 1);
		}
		count += ft_print_digit(nbr, base);
		if (wid > ft_max(dig_cnt, pre))
		{
			i = wid - ft_max(dig_cnt, pre);
			while (i-- > 0)
				count += write(STDOUT_FILENO, " ", 1);
		}
	}
	else
		count += ft_print_digit(nbr, base);
	return (count);
}

int	ft_print_digit_zero(long nbr, char *base, int wid, int pre)
{
	int		count;
	int		dig_cnt;
	int		i;
	int		j;

	count = 0;
	dig_cnt = ft_digit_count_abs(nbr, base);
	if (nbr < 0)
		wid--;
	j = pre;
	if (dig_cnt < wid || dig_cnt < pre)
	{
		if (wid > ft_max(dig_cnt, pre))
		{
			if (nbr < 0)
			{
				count += write(STDOUT_FILENO, "-", 1);
				nbr *= -1;
			}
			i = wid - ft_max(dig_cnt, pre);
			while (i-- > 0)
				count += write(STDOUT_FILENO, "0", 1);
		}
		while (j-- > dig_cnt)
			count += write(STDOUT_FILENO, "0", 1);
		count += ft_print_digit(nbr, base);
	}
	else
		count += ft_print_digit(nbr, base);
	return (count);
}

int	ft_print_digit_emty(long nbr, char *base, int wid, int pre)
{
	int		count;
	int		dig_cnt;
	int		i;
	int		j;

	count = 0;
	dig_cnt = ft_digit_count_abs(nbr, base);
	if (nbr < 0)
		wid--;
	j = pre;
	if (dig_cnt < wid || dig_cnt < pre)
	{
		if (wid > ft_max(dig_cnt, pre))
		{
			i = wid - ft_max(dig_cnt, pre);
			while (i-- > 0)
				count += write(STDOUT_FILENO, " ", 1);
		}
		if (nbr < 0)
		{
			count += write(STDOUT_FILENO, "-", 1);
			nbr *= -1;
		}
		while (j-- > dig_cnt)
		{
			count += write(STDOUT_FILENO, "0", 1);
		}
		count += ft_print_digit(nbr, base);
	}
	else
		count += ft_print_digit(nbr, base);
	return (count);
}
