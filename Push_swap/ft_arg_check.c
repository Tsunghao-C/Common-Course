/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 17:03:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arg_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (!ft_atoi(av[i]) && ft_strcmp(av[i], "0"))
			return (-1);
		i++;
	}
	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (i - 1);
}
