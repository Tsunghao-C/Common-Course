/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:57:53 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/23 17:14:45 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
/* Optimized approach - "Word-Sized Operations"
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byte_ptr;
	unsigned char	byte_value;
	size_t	*word_ptr;
	size_t	word_value;

	byte_ptr = (unsigned char *)s;
	byte_value = (unsigned char)c;
	word_value = byte_value;
	word_value |= word_value << 8;
	word_value |= word_value << 16;
	if (sizeof(size_t) == 8)
		word_value |= word_value << 32;
	while ((n > 0) && ((size_t)byte_ptr % sizeof(size_t) != 0))
	{
		*byte_ptr++ = byte_value;
		n--;
	}
	word_ptr = (size_t *)byte_ptr;
	while (n >= sizeof(size_t))
	{
		*word_ptr++ = word_value;
		n -= sizeof(size_t);
	}
	byte_ptr = (unsigned char *)word_ptr;
	while (n > 0)
	{
		*byte_ptr++ = byte_value;
		n--;
	}
	return (s);
}*/
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
