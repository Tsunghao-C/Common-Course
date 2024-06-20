/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alt_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:55:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 19:57:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_alt(char *base)
{
	int	count;

	count = 0;
	if (ft_strncmp(base, HEX_TAB, 16) == 0)
		count += write(STDOUT_FILENO, "0x", 2);
	else if (ft_strncmp(base, HEX_TAB_U, 16) == 0)
		count += write(STDOUT_FILENO, "0X", 2);
	else
		count += 0;
	return (count);
}
