/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:33:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 23:27:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (siz > 0)
	{
		while ((i < (siz - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
#include <bsd/string.h>
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
