/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:05:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 16:17:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			cnt++;
		i++;
	}
	return (cnt);
}
/*
#include <stdio.h>
int	ft_with_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	int	i;

	i = ft_count_if(av, &ft_with_a);
	printf("return of count if is: %d\n", i);
	return (0);
}*/
