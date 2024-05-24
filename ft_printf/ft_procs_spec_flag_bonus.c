/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procs_spec_flag_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:13:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 16:02:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_procs_spec_flag(const char *fmt, va_list *ap, int *count)
{
	int	i;
	int	min_wid;
	int	sign;
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
	if (sign == -1)
		*count += ft_print_spec_left(*(fmt + i), ap, min_wid, pre_spc);
	else if (sign == 0)
		*count += ft_print_spec_zero(*(fmt + i), ap, min_wid, pre_spc);
	else
		*count += ft_print_spec_emty(*(fmt + i), ap, min_wid, pre_spc);
	return ((char *)(fmt + i));
}
/* sign =  1 => right-empty
 * sign =  0 => right-zero
 * sign = -1 => left-empty
*/
