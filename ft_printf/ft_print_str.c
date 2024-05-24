/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:00:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 16:11:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	count;

	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	count = 0;
	while (*s)
		count += ft_print_char(*(s++));
	return (count);
}
