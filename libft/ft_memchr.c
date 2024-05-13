/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 12:31:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned int	i;
	void			*tmp;

	i = 0;
	tmp = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == c)
		{
			tmp = (void *)(s + i);
			return (tmp);
		}
		i++;
	}
	return (tmp);
}
/*
#include <stdio.h>
#include <string.h>

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
