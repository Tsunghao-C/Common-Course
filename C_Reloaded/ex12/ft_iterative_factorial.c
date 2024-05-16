/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:56:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 12:02:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i *= nb;
		nb--;
	}
	return (i);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_iterative_factorial(atoi(av[1])));
	return (0);
}*/
