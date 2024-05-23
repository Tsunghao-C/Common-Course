/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:27:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 23:10:09 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	const char	*last;

	tmp = s;
	last = NULL;
	while (*tmp != '\0')
	{
		if (*tmp == (unsigned char)c)
			last = tmp;
		tmp++;
	}
	if ((unsigned char)c == 0)
		return ((char *)tmp);
	return ((char *)last);
}
/* //Int Counter Version
char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	tmp = 0;
	len = (int)ft_strlen(s);
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
}*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "tripouille";
	char	*test;
	char	*real;

	test = ft_strrchr(s, 'z');
	real = strrchr(s, 'z');
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
