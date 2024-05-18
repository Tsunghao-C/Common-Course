/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:04 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/18 12:49:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	void	*args;

	va_start(ap, fmt);	/* initialize ap */
	args = va_arg(ap, char *);
	while (*fmt)
	{
		//check whether it is a specifier "%"
		if (*fmt == 37)
		{
			//"%" format specifiers, print arg and move to next arg
			fmt = ft_print_spec((char *)fmt, &args, &ap);
		}
		else
			fmt = ft_print_char((char *)fmt);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	printf(" ==> My function <==\n");
	ft_printf("Try to print string with backlash %%\\ \" \a \b \e \f \n \r \t \v oct\060 hex\x5a uni\u2B50");
	printf("\n ==> Real function <==\n");
	printf("Try to print string with backlash %%\\ \" \a \b \e \f \n \r \t \v oct\060 hex\x5a uni\u2B50");
	printf("\n");
	return (0);
}
