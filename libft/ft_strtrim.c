/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:49:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/22 09:15:27 by tsuchen          ###   ########.fr       */
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
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[start], set) == 1)
		start++;
	while (end >= start && ft_isset(s1[end], set) == 1)
		end--;
	len = end - start + 1;
	output = (char *)malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_strlcpy(output, s1 + start, (len + 1));
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
	char s1[] = "lorem ipsum dolor sit amet";
	
	char *strtrim;

	strtrim = ft_strtrim(s1, "te");
	printf("%s\n", s1);
	ft_print_result(strtrim);
	return (0);
}*/
/*
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
