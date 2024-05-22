/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/22 10:35:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = 0;
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
		{
			tmp = (char *)(s + len);
			return (tmp);
		}
		len--;
	}
	return (tmp);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "tripouille";
	char	*test;
	char	*real;

	test = ft_strrchr(s, 't' + 256);
	real = strrchr(s, 't' + 256);
	printf("test :%s\n", test);
	printf("real :%s\n", real);
	printf("cmp  :%d\n", strcmp(test, real));
	return (0);
}*/
/*
int	main(int ac, char *av[])
{
	if ((ac != 3) || (strlen(av[2]) != 1))
	{
		printf("Input Error\n");
		return (0);
	}
	char	*test;
	char	*real_strrchr;
	char	*real_strchr;

	test = ft_strrchr(av[1], *(av[2]));
	real_strrchr = strrchr(av[1], *(av[2]));
	real_strchr = strchr(av[1], *(av[2]));
	printf("test address: %p\n", test);
	printf("real_strrchr address: %p\n", real_strrchr);
	printf("real_strchr address: %p\n", real_strchr);
	return (0);
}*/
