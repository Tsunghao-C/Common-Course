/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem_f_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/27 17:57:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_mem_f(void *addr, char *flags, char **wid_pre)
{
	int				count;
	int				wid;
	int				prt_len;
	unsigned long	ad;

	ad = (unsigned long)addr;
	prt_len = 3;
	while (ad > 0)
	{
		prt_len += 1;
		ad /= HEX_SIZE;
	}
	wid = 0;
	if (wid_pre[0])
		wid = ft_atoi(wid_pre[0]);
	count = 0;
	if (ft_is_left(flags) == 1)
		count += ft_print_mem(addr);
	while (wid-- >= prt_len)
		count += write(STDOUT_FILENO, " ", 1);
	if (ft_is_left(flags) == 0)
		count += ft_print_mem(addr);
	return (count);
}
/* Note
 * 1. Only '-', '0' are acceptable flags.
 * 2. There is no precision allowed in "p" -> use origin function
 * 3. min prt_len is 3 becaus "0x_"
 */
