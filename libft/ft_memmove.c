/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/15 11:52:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*buf;

	i = 0;
	buf = malloc((n + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (i < n)
	{
		buf[i] = ((unsigned char *)src)[i];
		i++;
	}
	buf[i] = '\0';
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = buf[i];
		i++;
	}
	free(buf);
	return (dest);
}
/*
#include <string.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
		ft_putchar(str[i++]);
}

int	main(void)
{
	char	arr_test[] = "Standard Deviation";
	char	arr_real[] = "Standard Deviation";
	char	arr_real_cpy[] = "Standard Deviation";

	ft_memmove(arr_test + 4, arr_test + 9, 9 * sizeof(char));
	ft_putstr(arr_test, sizeof(arr_test));
	write(1, "\n", 1);
	memmove(arr_real + 4, arr_real + 9, 9 * sizeof(char));
	ft_putstr(arr_real, sizeof(arr_real));
	write(1, "\n", 1);
	memcpy(arr_real_cpy + 4, arr_real_cpy + 9, 9 * sizeof(char));
	ft_putstr(arr_real_cpy, sizeof(arr_real_cpy));
	write(1, "\n", 1);
	return (0);
}*/
