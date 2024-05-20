/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:13:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/20 19:35:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_spec_flag(const char *fmt, va_list *ap, int *count)
{
	int	i;
	int	sign;
	int	min_wid;
	int	pre_spc;

	i = 0;
	sign = 1;
	if (*fmt == '-' || *fmt == '0')
	{
		if (*fmt == '-')
			sign = -1;
		else
			sign = 0;
		fmt++;
	}
	while (ft_is_spec(fmt[i]) == 0)
		i++;
	ft_gen_wid_pre(fmt, i, &min_wid, &pre_spc);
	*count += ft_print_spec(*fmt, &ap, sign, min_wid, pre_spc);
	/* printf_digit, print_str need to genralize */
	return (fmt + i);
}
