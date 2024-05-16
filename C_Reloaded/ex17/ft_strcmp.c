/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:04:56 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 14:11:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("test is: %d\n", ft_strcmp(av[1], av[2]));
	printf("real is: %d\n", strcmp(av[1], av[2]));
	return (0);
}*/
