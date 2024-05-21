/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:49:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/21 23:22:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (ft_isset(s1[i], set) == 1)
			j++;
	}
	output = (char *)malloc((i - j + 1) * sizeof(char));
	if (!output)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (ft_isset(s1[i], set) == 0)
			output[j++] = s1[i];
	}
	output[j] = '\0';
	return (output);
}
/*
#include <stdio.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char s1[] = " lorem ipsum dolor sit amet";
	
	char *strtrim;

	strtrim = ft_strtrim(s1, "l ");
	ft_print_result(strtrim);
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	char	*str_trim;

	str_trim = ft_strtrim(av[1], av[2]);
	if (!str_trim)
		return (0);
	printf("Trimmed str is: %s\n", str_trim);
	free(str_trim);
	return (0);
}*/
