/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:06:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 15:20:04 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = (int *)malloc((max - min) * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	int	*tab;
	int	size;
	int	i;

	tab = ft_range(atoi(av[1]), atoi(av[2]));
	size = (atoi(av[2]) - atoi(av[1]));
	i = 0;
	while (i < size)
		printf("%d ", tab[i++]);
	free(tab);
	return (0);
}*/
