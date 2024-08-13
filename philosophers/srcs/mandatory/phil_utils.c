/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:10:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/14 01:50:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_phil(t_philo *phil, int i, t_setup *setting)
{
	phil->id = i + 1;
	phil->status = EATING;
	*(setting->last_meal + i) = setting->start;
	phil->num_meals = 0;
	phil->is_full = 0;
	phil->setting = setting;
}

int	init_setting(int ac, char *av[], t_setup *set)
{
	set->phils = ft_atol(av[1]);
	set->time_to_die = ft_atol(av[2]);
	set->time_to_eat = ft_atol(av[3]);
	set->time_to_sleep = ft_atol(av[4]);
	set->time_to_think = 0;
	if (set->time_to_sleep <= set->time_to_eat)
		set->time_to_think = 2 * set->time_to_eat - set->time_to_sleep;
	set->must_eat_times = 0;
	if (ac == 6)
		set->must_eat_times = ft_atol(av[5]);
	gettimeofday(&set->start, NULL);
	set->died = 0;
	set->fulled_phils = 0;
	set->last_meal = malloc(set->phils * sizeof(struct timeval));
	if (!set->last_meal)
		return (1);
	set->mtx_fork = NULL;
	set->mtx_full = NULL;
	set->mtx_dead = NULL;
	set->mtx_meal = NULL;
	set->mtx_print = NULL;
	return (0);
}

void	init_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
		pthread_mutex_t mtx[4])
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
	pthread_mutex_init(mtx + PRINT, NULL);
	setting->mtx_fork = mtx_fork;
	setting->mtx_full = mtx + FULL;
	setting->mtx_dead = mtx + DEAD;
	setting->mtx_meal = mtx + MEAL;
	setting->mtx_print = mtx + PRINT;
}

void	destroy_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
		pthread_mutex_t mtx[4])
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
	pthread_mutex_destroy(mtx + PRINT);
	free(mtx_fork);
}

void	print_message(t_setup *setting, int id, t_task action)
{
	pthread_mutex_lock(setting->mtx_print);
	if (action == THINKING)
		printf("%05u %2d is thinking\n", get_time(&setting->start), id);
	else if (action == EATING)
		printf("%05u %2d is eating\n", get_time(&setting->start), id);
	else if (action == SLEEPING)
		printf("%05u %2d is sleeping\n", get_time(&setting->start), id);
	else if (action == FORK)
		printf("%05u %2d has taken a fork\n", get_time(&setting->start), id);
	else if (action == DIED)
		printf("%05u %2d died\n", get_time(&setting->start), id);
	pthread_mutex_unlock(setting->mtx_print);
}
