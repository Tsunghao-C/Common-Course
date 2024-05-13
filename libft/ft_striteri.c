/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:10:55 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/09 20:09:58 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s);
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
