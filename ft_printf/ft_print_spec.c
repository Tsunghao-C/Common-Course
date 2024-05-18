/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:26:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/18 12:49:36 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_spec(char *fmt, void **args, va_list *ap)
{
	if (*(fmt + 1) == 'c')
	{
		ft_putchar_fd((char)(*args), STDOUT_FILENO);
		*args = va_arg(*ap, char);
	}
	if (*(fmt + 1) == 's')
	{
		ft_putstr_fd((char *)(*args), STDOUT_FILENO);
		*args = va_arg(*ap, char *);
	}
	if (*(fmt + 1) == 'p')
	{
		ft_putmem_fd((void *)(*args), STDOUT_FILENO);
		*args = va_arg(*ap, void *);
	}
	if (*(fmt + 1) == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	fmt+=2;
	return (fmt);
}
