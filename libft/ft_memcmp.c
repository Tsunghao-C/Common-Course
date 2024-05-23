/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 19:10:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (((unsigned char *)s1)[i]
		== ((unsigned char *)s2)[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
/* //Add NULL tests
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*ptr;

	ptr = NULL;
	printf("Check ptr conditions\n");
	printf("one of s1 s2 is ptr\n");
	printf("%d\n", memcmp(ptr, "  ", 0));
	printf("%d\n", ft_memcmp(ptr, "  ", 0));
	//printf("%d\n", memcmp(ptr, "  ", 2));
	//printf("%d\n", ft_memcmp(ptr, "  ", 2));
	printf("both s1 s2 is ptr\n");
	printf("%d\n", memcmp(ptr, ptr, 0));
	printf("%d\n", ft_memcmp(ptr, ptr, 0));
	//printf("%d\n", memcmp(ptr, ptr, 2));
	//printf("%d\n", ft_memcmp(ptr, ptr, 2));
	return (0);
}*/
/*
int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		printf("Input Error\n");
		return (0);
	}
	int	test;
	int	real;

	test = ft_memcmp(av[1], av[2], atoi(av[3]));
	real = memcmp(av[1], av[2], atoi(av[3]));
	printf("test cmp: %d\n", test);
	printf("real cmp: %d\n", real);
	return (0);
}*/
