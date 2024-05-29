/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_f_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:50:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/29 17:10:39 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_print_str_f(char *s, char *flags, char **wid_pre)
{
	int		count;
	int		prt_len;
	int		wid;
	char	*tmp;

	tmp = s;
	if (!s)
		tmp = "(null)";
	if (!s && wid_pre[1] && ft_atoi(wid_pre[1]) < 6)
		tmp = "";
	count = 0;
	prt_len = ft_strlen(tmp);
	if (wid_pre[1])
		prt_len = ft_min(ft_strlen(tmp), ft_atoi(wid_pre[1]));
	if (ft_is_left(flags) == 1)
		count += write(STDOUT_FILENO, tmp, prt_len);
	wid = 0;
	if (wid_pre[0])
		wid = ft_atoi(wid_pre[0]);
	while (wid-- > prt_len)
		count += write(STDOUT_FILENO, " ", 1);
	if (ft_is_left(flags) == 0)
		count += write(STDOUT_FILENO, tmp, prt_len);
	return (count);
}
/* Note
 * For string, the only flag acceptable is '-'
 */
