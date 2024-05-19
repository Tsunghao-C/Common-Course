/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:00:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/19 11:46:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += ft_print_char(*(s++)); 
	return (count);
}
