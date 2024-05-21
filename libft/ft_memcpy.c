/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 10:22:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	arr_t[50] = "Standard Deviation";
	char	arr_r[50] = "Standard Deviation";
	char	arr_c[50] = "Standard Deviation";
	char	*test1;
	char	*real1, *real2;

	printf("Original string    :%s\n", arr_t);
	test1 = arr_t;
	real1 = arr_r;
	real2 = arr_c;
	ft_memcpy(test1 + 8, test1, 12);
	printf("ft_memcpy overlap  :%s\n", arr_t + 8);
	memcpy(real2 + 8, real2, 12);
	printf("memcpy overlap     :%s\n", (arr_c + 8));
	memmove(real1 + 8, real1, 12);
	printf("memmove overlap    :%s\n", arr_r + 8);
	return (0);
}*/
