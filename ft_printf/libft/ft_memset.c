/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/15 11:55:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
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
	char	arr_test[9];
	char	arr_real[9];

	ft_memset(arr_test, 48, sizeof(arr_test));
	memset(arr_real, 49, sizeof(arr_real));
	ft_putstr(arr_test, sizeof(arr_test));
	write(1, "\n", 1);
	ft_putstr(arr_real, sizeof(arr_real));
	write(1, "\n", 1);
	return (0);
}
//memset is used to initialize or zero out an array of memory.
*/
