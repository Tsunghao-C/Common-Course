/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_f_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:37:36 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/29 16:12:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char_f(char c, char *flags, char **wid_pre)
{
	int	count;
	int	wid;

	wid = 0;
	if (wid_pre[0])
		wid = ft_atoi(wid_pre[0]);
	count = 0;
	if (ft_is_left(flags) == 1)
		count += ft_print_char(c);
	while (wid-- > 1)
	{
		if (c == '%' && ft_have_zero(flags) == 1)
			count += write(STDOUT_FILENO, "0", 1);
		else
			count += write(STDOUT_FILENO, " ", 1);
	}
	if (ft_is_left(flags) == 0)
		count += ft_print_char(c);
	return (count);
}
/* Note
 * For specifier "c", the flag can only be '-'
 * There is no precision allowed in "c"
 */
