/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:10:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/08 19:20:04 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(struct timeval *ref)
{
	struct timeval	current;
	unsigned long	diff;

	gettimeofday(&current, NULL);
	diff = (current.tv_sec - ref->tv_sec) * 1000;
	diff += (current.tv_usec - ref->tv_usec) / 1000;
	return (diff);
}

void	init_phil(t_philo *phil, int i, t_setup *setting)
{
	phil->id = i;
	phil->status = THINKING;
	*(setting->last_meal + i) = setting->start;
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
		{
			write(ER, "Wrong input. Must be positive numbers\n", 38);
			return (1);
		}
	}
	setting->phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]);
	setting->time_to_eat = ft_atol(av[3]);
	setting->time_to_sleep = ft_atol(av[4]);
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	gettimeofday(&setting->start, NULL);
	setting->last_meal = malloc(setting->phils * sizeof(struct timeval));
	if (!setting->last_meal)
		return (2);
	setting->mtx_fork = NULL;
	setting->died = 0;
	return (0);
}

void	init_mutex(t_setup *setting, pthread_mutex_t *mtx_fork)
{
	unsigned int	i;

	i = 0;
	while (i < setting->phils)
	{
		pthread_mutex_init(mtx_fork + i, NULL);
		i++;
	}
	setting->mtx_fork = mtx_fork;
}

void	destroy_mutex(t_setup *setting, pthread_mutex_t *mtx_fork)
{
	unsigned int	i;

	i = 0;
	while (i < setting->phils)
	{
		pthread_mutex_destroy(mtx_fork + i);
		i++;
	}
	free(mtx_fork);
}
