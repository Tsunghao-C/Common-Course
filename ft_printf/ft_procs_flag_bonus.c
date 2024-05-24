/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procs_spec_flag_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:13:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 17:52:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

char	*ft_procs_flag(const char *fmt, va_list *ap, int *count)
{
	int	i;
	int	wid;
	int	pre;
	char	*flags;

	i = 0;
	/* the flags '-' '#' '+' '0' don't have a certain order
	 * but must be before width numbers and precisions '.'
	 */
	// moved to non-flags
	while (ft_is_flag(fmt[i]) == 1)
		i++;
	flags = (char *)malloc((i + 1) * sizeof(char));
	if (!flags)
		return (0);
	ft_strlcpy(flags, fmt, (i + 1));
	fmt = fmt + i;
	// checked wid and pre
	while (ft_is_spec(fmt[i]) == 1)
		i++;
	ft_gen_wid_pre(fmt, i, &wid, &pre);
	// analyze flags and add wid, pre to print accordingly
	if (sign == -1)
		*count += ft_print_spec_left(*(fmt + i), ap, wid, pre);
	else if (sign == 0)
		*count += ft_print_spec_zero(*(fmt + i), ap, wid, pre);
	else
		*count += ft_print_spec_emty(*(fmt + i), ap, wid, pre);
	return ((char *)(fmt + i));
}
/* sign =  1 => right-empty
 * sign =  0 => right-zero
 * sign = -1 => left-empty
*/
