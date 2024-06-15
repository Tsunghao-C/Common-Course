/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procs_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:13:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 18:42:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

static void	ft_free_all(int n, char **arr, char *flags)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	free(flags);
}

const char	*ft_procs_flag(const char *fmt, va_list *ap, int *count)
{
	const char	*tmp;
	char		*flags;
	char		**wid_pre;

	tmp = fmt;
	while (ft_is_flag(*tmp) == 1)
		tmp++;
	flags = (char *)malloc((tmp - fmt + 1) * sizeof(char));
	if (!flags)
		return (NULL);
	ft_strlcpy(flags, fmt, (tmp - fmt + 1));
	fmt = tmp;
	while (*tmp && ft_is_spec(*tmp) == 0)
		tmp++;
	wid_pre = (char **)ft_calloc(3, sizeof(char *));
	if (!wid_pre)
		return (free(flags), NULL);
	if (!*tmp)
		return (ft_free_all(3, wid_pre, flags), NULL);
	ft_gen_wid_pre(fmt, tmp - fmt, wid_pre);
	*count += ft_print_spec_f(*(tmp), ap, flags, wid_pre);
	ft_free_all(3, wid_pre, flags);
	return (tmp);
}
/* the flags '-' '#' '+' '0' don't have a certain order
 * but must be before width numbers and precisions '.'
 */
// 1. move to non-flags and save all the flags into a string (flags)
// 2. move to specifier and generate wid and pre into a tab of int (wid_pre)
// 3. send "flags" and "wid_pre" together with ap to print and return cnt
/*
	if (sign == -1)
		*count += ft_print_spec_left(*(fmt + i), ap, wid, pre);
	else if (sign == 0)
		*count += ft_print_spec_zero(*(fmt + i), ap, wid, pre);
	else
		*count += ft_print_spec_emty(*(fmt + i), ap, wid, pre);
*/
