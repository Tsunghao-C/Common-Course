/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:49:11 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 15:59:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_spec(char c)
{
	if (c == '%' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}
