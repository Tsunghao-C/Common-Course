/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 19:41:57 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)(tmp + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("%s\n", (char *)memchr(tab, -1, 7));
}
int	main(int ac, char *av[])
{
	if ((ac != 3) || (strlen(av[2]) != 1))
	{
		printf("Input Error\n");
		return (0);
	}
	char	*test;
	char	*real_memchr;
	char	*real_strchr;

	test = ft_memchr(av[1], *(av[2]), sizeof(av[1]));
	real_memchr = memchr(av[1], *(av[2]), sizeof(av[1]));
	real_strchr = strchr(av[1], *(av[2]));
	printf("test address: %p\n", test);
	printf("real_memchr address: %p\n", real_memchr);
	printf("real_strchr address: %p\n", real_strchr);
	return (0);
}*/
