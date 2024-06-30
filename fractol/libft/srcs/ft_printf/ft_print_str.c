/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:00:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 13:53:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int		count;
	char	*tmp;

	if (!s)
		tmp = "(null)";
	else
		tmp = s;
	count = 0;
	count += write(STDOUT_FILENO, tmp, ft_strlen(tmp));
	return (count);
}
