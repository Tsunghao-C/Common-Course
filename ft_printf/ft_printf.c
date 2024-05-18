/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:04 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/17 18:19:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	va_list ap2;
	void	*args;

	va_start(ap, fmt);	/* initialize ap */
	va_copy(ap2, ap);	/* a duplicate of inital ap */
	args = va_arg(ap, char *);
	while (*fmt)
	{
		//check whether it is a specifier "%"
		if (*fmt == 37)
		{
			//"%" format specifiers, print arg and move to next arg
			ft_print_spec();
			args = va_arg(ap, /* depend on what type */); 
		}
		else if (*fmt == 92)
		{
			// "\" escape char, check the next character and print
			// need to move by 2 or more bytes depending of what
			// is after "\"
			fmt = ft_print_escp(fmt);
		}
		else
			ft_print_char(fmt);
	}
	va_end(ap);
}
