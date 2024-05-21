/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 10:16:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	tmp = dest;
	if (src == dest)
		return (tmp);
	if (src > dest)
	{
		while (n-- > 0)
			*(unsigned char *)(dest++) = *(unsigned char *)(src++);
	}
	else
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (tmp);
}
/*//malloc version 
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*buf;

	i = 0;
	buf = malloc((n + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (i < n)
	{
		buf[i] = ((unsigned char *)src)[i];
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = buf[i];
		i++;
	}
	free(buf);
	return (dest);
}*/
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
	ft_memmove(test1 + 8, test1, 12);
	printf("ft_memmove overlap :%s\n", arr_t + 8);
	memmove(real1 + 8, real1, 12);
	printf("memmove overlap    :%s\n", arr_r + 8);
	memcpy(real2 + 8, real2, 12);
	printf("memcpy overlap     :%s\n", (arr_c + 8));
	return (0);
}*/
