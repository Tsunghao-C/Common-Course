/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:37:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 13:55:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	float	i;

	i = 1;
	while (i <= ((i + (nb / i)) / 2))
	{
		if (i == ((i + (nb / i)) / 2))
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_sqrt(atoi(av[1])));
	return (0);
}*/
