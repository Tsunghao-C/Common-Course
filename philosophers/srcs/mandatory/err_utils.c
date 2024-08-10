/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:20:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/10 20:03:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_all_full(t_setup *setting)
{
	int	i;

	i = 0;
	pthread_mutex_lock(setting->mtx_full);
	if (setting->fulled_phils == setting->phils)
		i = 1;
	pthread_mutex_unlock(setting->mtx_full);
	return (i);
}

int	check_starved_time(int id, t_setup *setting)
{
	int	i;

	i = 0;
	pthread_mutex_lock(setting->mtx_meal);
	if (get_time(setting->last_meal + id) > setting->time_to_die)
		i = 1;
	pthread_mutex_unlock(setting->mtx_meal);
	return (i);
}

int	check_sb_dead(t_setup *setting)
{
	int	i;

	i = -1;
	pthread_mutex_lock(setting->mtx_dead);
	if (setting->died)
		i = 0;
	pthread_mutex_unlock(setting->mtx_dead);
	return (i);
}
