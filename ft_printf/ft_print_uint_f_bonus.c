/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_f_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/29 15:35:24 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rm_alt(char *str)
{
	while (*str)
	{
		if (*str == '#')
			*str = ' ';
		str++;
	}
}

static int	ft_print_alt(char *base)
{
	int	count;

	count = 0;
	if (ft_strncmp(base, HEX_TAB, 16) == 0)
		count += write(STDOUT_FILENO, "0x", 2);
	else if (ft_strncmp(base, HEX_TAB_U, 16) == 0)
		count += write(STDOUT_FILENO, "0X", 2);
	else
		count += 0;
	return (count);
}

static int	ft_print_pre(long nbr, char *base, int *prt_len, char *flags)
{
	int	count;
	int	dgt_cnt;

	dgt_cnt = ft_dgt_cnt_abs(nbr, base);
	count = 0;
	if (ft_have_alt(flags) == 1 && nbr != 0)
	{
		count += ft_print_alt(base);
		*prt_len -= 2;
	}
	while (*prt_len > dgt_cnt)
	{
		count += write(STDOUT_FILENO, "0", 1);
		dgt_cnt++;
	}
	if (*prt_len)
		count += ft_print_digit(nbr, base);
	return (count);
}

static int	ft_print_wid(char **wid_pre, char *flags, int *prt_len)
{
	int	count;
	int	wid;	

	count = 0;
	wid = 0;
	if (wid_pre[0])
		wid = ft_atoi(wid_pre[0]);
	if (ft_have_space(flags) == 1)
		wid -= 2;
	while (wid > *prt_len)
	{
		if (ft_have_zero(flags) == 1 && !wid_pre[1])
			count += write(STDOUT_FILENO, "0", 1);
		else
			count += write(STDOUT_FILENO, " ", 1);
		wid--;
	}
	return (count);
}

int	ft_print_uint_f(long nbr, char *base, char *flags, char **wid_pre)
{
	int	count;
	int	prt_len;

	count = 0;
	prt_len = ft_dgt_cnt_abs(nbr, base);
	if (wid_pre[1] && ft_atoi(wid_pre[1]) > prt_len)
		prt_len = ft_atoi(wid_pre[1]);
	if (wid_pre[1] && ft_atoi(wid_pre[1]) == 0 && nbr == 0)
		prt_len -= 1;
	if (ft_have_alt(flags) == 1 && nbr != 0)
	{
		if (ft_have_zero(flags) == 1 && !wid_pre[1])
		{
			count += ft_print_alt(base);
			ft_rm_alt(flags);
		}
		else
			prt_len += 2;
	}
	if (ft_is_left(flags) == 1)
		count += ft_print_pre(nbr, base, &prt_len, flags);
	count += ft_print_wid(wid_pre, flags, &prt_len);
	if (ft_is_left(flags) == 0)
		count += ft_print_pre(nbr, base, &prt_len, flags);
	return (count);
}
/* Note
 * 1. possible combination of flags for u: '-' '0'
 * 2. possible combination of flags for x X: '-' '0' '#'
 * 3. if precision is not null, the '0' flag is ignored
 */
