/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 15:30:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = 0;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == c)
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
