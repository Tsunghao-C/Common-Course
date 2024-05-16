/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 09:32:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
		ft_putchar(str[i++]);
}

int	main(void)
{
	char	arr_src[10];
	char	arr_test[13];
	char	arr_real[13];

	memset(arr_src, 50, sizeof(arr_src));
	memset(arr_test, 48, sizeof(arr_test));
	memset(arr_real, 49, sizeof(arr_real));
	ft_putstr(ft_memcpy(arr_test, arr_src, sizeof(arr_src)), sizeof(arr_test));
	write(1, "\n", 1);
	ft_putstr(memcpy(arr_real, arr_src, sizeof(arr_src)), sizeof(arr_real));
	write(1, "\n", 1);
	return (0);
}*/
