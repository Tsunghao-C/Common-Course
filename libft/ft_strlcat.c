/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:34:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 17:29:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (siz < dst_len + 1)
		return (src_len + siz);
	i = 0;
	while (src[i] && i < (siz - dst_len - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h>
//#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	char	b[0xF] = "nyan !";

	printf("%lu\n", strlcat(NULL, "fake", 2));
	printf("%zu\n", ft_strlcat(NULL, "fake", 2));
	return (0);
}*/
/*
int	main(void)
{
	char	src[10] = "123456789";
	char	dest_test[16] = "hello yo";
	char	dest_real[16] = "hello yo";

	printf("test: %zu\n", ft_strlcat(dest_test, src, 16));
	printf("test text: %s\n", dest_test);
	printf("real: %zu\n", strlcat(dest_real, src, 16));
	printf("test real: %s\n", dest_real);
	return (0);
}*/
