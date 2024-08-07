/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:10:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 15:12:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_usec);
}

void	init_phil(t_philo *phil, int i, t_setup *setting)
{
	phil->id = i;
	phil->status = THINKING;
	phil->beg_lastmeal = setting->start_time;
	phil->num_meals = 0;
	phil->setting = setting;
}

int	input_check(int ac, char *av[], t_setup *setting)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
			return (1);
	}
	setting->num_of_phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]) * 1000;
	setting->time_to_eat = ft_atol(av[3]) * 1000;
	setting->time_to_sleep = ft_atol(av[4]) * 1000;
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	setting->start_time = get_time();
	return (0);
}
