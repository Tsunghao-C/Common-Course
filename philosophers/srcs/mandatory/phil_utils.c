/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:10:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/10 19:58:49 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

__uint32_t	get_time(struct timeval *ref)
{
	struct timeval	current;
	__uint32_t		diff;

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
	phil->is_full = 0;
	phil->setting = setting;
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
	setting->last_meal = malloc(setting->phils * sizeof(struct timeval));
	if (!setting->last_meal)
		return (1);
	setting->mtx_fork = NULL;
	setting->mtx_full = NULL;
	setting->mtx_dead = NULL;
	setting->mtx_meal = NULL;
	return (0);
}

void	init_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
		pthread_mutex_t mtx[3])
{
	__uint16_t	i;

	i = 0;
	while (i < setting->phils)
	{
		pthread_mutex_init(mtx_fork + i, NULL);
		i++;
	}
	pthread_mutex_init(mtx + FULL, NULL);
	pthread_mutex_init(mtx + DEAD, NULL);
	pthread_mutex_init(mtx + MEAL, NULL);
	setting->mtx_fork = mtx_fork;
	setting->mtx_full = mtx + FULL;
	setting->mtx_dead = mtx + DEAD;
	setting->mtx_meal = mtx + MEAL;
}

void	destroy_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
		pthread_mutex_t mtx[3])
{
	__uint16_t	i;

	i = 0;
	while (i < setting->phils)
	{
		pthread_mutex_destroy(mtx_fork + i);
		i++;
	}
	pthread_mutex_destroy(mtx + FULL);
	pthread_mutex_destroy(mtx + DEAD);
	pthread_mutex_destroy(mtx + MEAL);
	free(mtx_fork);
}
