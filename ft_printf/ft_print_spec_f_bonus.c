/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec_f_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:26:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/29 16:12:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_spec_f(char c, va_list *ap, char *flags, char **wid_pre)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char_f(va_arg(*ap, int), flags, wid_pre);
	else if (c == 's')
		count += ft_print_str_f(va_arg(*ap, char *), flags, wid_pre);
	else if (c == 'p')
		count += ft_print_mem_f(va_arg(*ap, void *), flags, wid_pre);
	else if (c == 'd' || c == 'i')
		count += ft_print_sint_f(va_arg(*ap, int), DEC_TAB, flags, wid_pre);
	else if (c == 'u')
		count += ft_print_uint_f(va_arg(*ap, unsigned int),
				DEC_TAB, flags, wid_pre);
	else if (c == 'x')
		count += ft_print_uint_f(va_arg(*ap, unsigned int),
				HEX_TAB, flags, wid_pre);
	else if (c == 'X')
		count += ft_print_uint_f(va_arg(*ap, unsigned int),
				HEX_TAB_U, flags, wid_pre);
	else if (c == '%')
		count += ft_print_char(c);
	else
		return (count);
	return (count);
}
