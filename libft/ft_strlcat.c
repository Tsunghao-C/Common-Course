/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:31:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 12:36:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *restrict dst, char const *restrict src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	i = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dstsize < (dst_len + 1))
		return (src_len + dstsize);
	while (src[i] && i < (dstsize - dst_len - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[10] = "123456789";
	char	dest_test[10] = "hello yo";
	char	dest_real[10] = "hello yo";

	printf("test: %u\n", ft_strlcat(dest_test, src, 10));
	printf("test text: %s\n", dest_test);
	printf("real: %zu\n", strlcat(dest_real, src, 10));
	printf("test real: %s\n", dest_real);
	return (0);
}*/
