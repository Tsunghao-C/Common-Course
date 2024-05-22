/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:02:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/22 12:46:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (start > ft_strlen(s))
		size = 0;
	else
		size = ft_min(ft_strlen(s) - start, len);
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (i < size && s[i + start])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;

	s = ft_substr("tripouille", 100, 1);
	printf("substr :%s\n", s);
	printf("strcmp :%d\n", strcmp(s, ""));
	free(s);
	return (0);
}*/
/*
int	main(int ac, char *av[])
{
	char	*substr;

	if (ac != 4)
		return (0);
	substr = ft_substr(av[1], atoi(av[2]), atoi(av[3]));
	printf("substr is: %s\n", substr);
	free(substr);
	return (0);
}*/
