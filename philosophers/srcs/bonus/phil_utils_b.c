/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:55:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/11 20:00:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	input_check(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		write(ER, "Need 4 or 5 args in the following order:\n", 41);
		write(ER, "num_of_phils time_to_die time_to_eat ", 37);
		write(ER, "time_to_sleep [optional]must_eat_times\n", 39);
		return (1);
	}
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
		{
			write(ER, "Wrong input. Must be positive numbers\n", 38);
			return (2);
		}
	}
	return (0);
}

int	init_setting(int ac, char *av[], t_setup *setting)
{
	setting->phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]);
	setting->time_to_eat = ft_atol(av[3]);
	setting->time_to_sleep = ft_atol(av[4]);
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	gettimeofday(&setting->start, NULL);
	setting->died = 0;
	setting->fulled_phils = 0;
	return (0);
}
