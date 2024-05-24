/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:10:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 11:19:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	str = (char *)malloc((s_len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* Note
 * 1. if s or f is NULL, it will crash
 * 2. if s is empty, it will return a new empty string
 * 3. if malloc failed, return NULL
 */
/*
#include <stdio.h>

char	zero_even(unsigned int idx, char c)
{
	if ((idx % 2) == 0)
		return ('0');
	return (c);
}

char	mute_odd(unsigned int idx, char c)
{
	if ((idx % 2) == 1)
		return (' ');
	return (c);
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	char	*str_map1;
	char	*str_map2;

	str_map1 = ft_strmapi(av[1], &zero_even);
	str_map2 = ft_strmapi(av[1], &mute_odd);
	printf("Strmap funtion_1 is: %s\n", str_map1);
	printf("Strmap funtion_2 is: %s\n", str_map2);
	free(str_map1);
	free(str_map2);
	return (0);
}*/
