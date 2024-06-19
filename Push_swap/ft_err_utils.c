/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:30:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 18:20:16 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_value_check(char **av)
{
	int		i;
	int		nbr;
	char	*tmp;

	i = 0;
	if (ft_strcmp(av[i], P_NAME) == 0)
		i++;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		tmp = ft_itoa(nbr);
		if ((!nbr && ft_strcmp(av[i], "0")) || ft_strcmp(tmp, av[i]))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		i++;
	}
	return (i);
}

static int	ft_dupli_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strcmp(av[i], P_NAME) == 0)
		i++;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j++]))
				return (-1);
		}
		i++;
	}
	return (i);
}

void	ft_arg_check(char **av)
{
	if (ft_value_check(av) < 0 || ft_dupli_check(av) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(0);
	}
}
