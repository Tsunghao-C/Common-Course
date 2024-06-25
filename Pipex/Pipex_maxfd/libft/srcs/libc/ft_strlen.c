/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:33:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 19:43:45 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
/* //Int counter method
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
#include <string.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("%u\n", ft_strlen(av[1]));
	printf("%u\n", strlen(av[1]i));
	return (0);
}*/
