/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:11:14 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/18 10:48:04 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_char(char *fmt)
{
	ft_putchar_fd(*fmt, STDOUT_FILENO);
	fmt++;
	return (fmt);
}
