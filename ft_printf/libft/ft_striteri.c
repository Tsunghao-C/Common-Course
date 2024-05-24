/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:10:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 11:24:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}
/* Note
 * 1. if s or f is NULL, it will crash
 */
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	iter(unsigned int i, char *c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	free(str);
	return (0);
}
void	zero_even(unsigned int idx, char *s)
{
	if ((idx % 2) == 0)
		s[idx] = '0';
}

void	mute_odd(unsigned int idx, char *s)
{
	if ((idx % 2) == 1)
		s[idx] = ' ';
}

int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	char	*str1;
	char	*str2;

	str1 = strdup(av[1]);
	str2 = strdup(av[1]);
	ft_striteri(str1, &zero_even);
	ft_striteri(str2, &mute_odd);
	printf("Strmap funtion_1 is: %s\n", str1);
	printf("Strmap funtion_2 is: %s\n", str2);
	free(str1);
	free(str2);
	return (0);
}*/
