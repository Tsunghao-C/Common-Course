/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:35:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 12:37:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *restrict dst, char const *restrict src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (dstsize > 0)
	{
		while ((i < (dstsize - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*src;
	char	dest[20];
	char	real_dest[20];
	int		test;
	int		real;

	src = "28HLKJHGVLJH<MN<J(**&^%*&^(M<M>Bsd";
	printf("str : %s\n", src);
	test = ft_strlcpy(dest, src, sizeof(dest));
	real = strlcpy(real_dest, src, sizeof(real_dest));
	printf("dest: %s - %d\n", dest, test);
	printf("real: %s - %d\n", real_dest, real);
	return (0);
}*/
