/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:26:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 19:05:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_spec_left(char c, va_list *ap, int wid, int pre)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(*ap, int));
	else if (c == 's')
		count += ft_print_str(va_arg(*ap, char *));
	else if (c == 'p')
		count += ft_print_mem(va_arg(*ap, void *));
	else if (c == 'd')
		count += ft_print_digit_left(va_arg(*ap, int), DEC_TAB, wid, pre);
	else if (c == 'i')
		count += ft_print_digit(va_arg(*ap, int), DEC_TAB);
	else if (c == 'u')
		count += ft_print_digit(va_arg(*ap, unsigned int), DEC_TAB);
	else if (c == 'x')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB);
	else if (c == 'X')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB_U);
	else
		count += ft_print_char(c);
	return (count);
}

int	ft_print_spec_zero(char c, va_list *ap, int wid, int pre)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(*ap, int));
	else if (c == 's')
		count += ft_print_str(va_arg(*ap, char *));
	else if (c == 'p')
		count += ft_print_mem(va_arg(*ap, void *));
	else if (c == 'd')
		count += ft_print_digit_zero(va_arg(*ap, int), DEC_TAB, wid, pre);
	else if (c == 'i')
		count += ft_print_digit(va_arg(*ap, int), DEC_TAB);
	else if (c == 'u')
		count += ft_print_digit(va_arg(*ap, unsigned int), DEC_TAB);
	else if (c == 'x')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB);
	else if (c == 'X')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB_U);
	else
		count += ft_print_char(c);
	return (count);
}

int	ft_print_spec_emty(char c, va_list *ap, int wid, int pre)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(*ap, int));
	else if (c == 's')
		count += ft_print_str(va_arg(*ap, char *));
	else if (c == 'p')
		count += ft_print_mem(va_arg(*ap, void *));
	else if (c == 'd')
		count += ft_print_digit_emty(va_arg(*ap, int), DEC_TAB, wid, pre);
	else if (c == 'i')
		count += ft_print_digit(va_arg(*ap, int), DEC_TAB);
	else if (c == 'u')
		count += ft_print_digit(va_arg(*ap, unsigned int), DEC_TAB);
	else if (c == 'x')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB);
	else if (c == 'X')
		count += ft_print_digit(va_arg(*ap, unsigned int), HEX_TAB_U);
	else
		count += ft_print_char(c);
	return (count);
}