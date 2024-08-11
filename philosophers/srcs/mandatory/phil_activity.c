/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_activity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:08:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/11 18:09:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	int	i;

	i = philo->id + 1;
	print_message(philo->setting, i, FORK);
	print_message(philo->setting, i, EATING);
	pthread_mutex_lock(philo->setting->mtx_meal);
	gettimeofday(philo->setting->last_meal + i - 1, NULL);
	pthread_mutex_unlock(philo->setting->mtx_meal);
	philo->num_meals += 1;
	if (philo->setting->must_eat_times && !philo->is_full)
	{
		if (philo->num_meals >= philo->setting->must_eat_times)
		{
			pthread_mutex_lock(philo->setting->mtx_full);
			philo->setting->fulled_phils += 1;
			pthread_mutex_unlock(philo->setting->mtx_full);
			philo->is_full = 1;
		}
	}
	usleep(philo->setting->time_to_eat * 1000);
}

int	eating_with_forks(t_philo *philo)
{
	int			i;
	__uint16_t	num_phils;

	i = philo->id + 1;
	num_phils = philo->setting->phils;
	pthread_mutex_lock(philo->setting->mtx_fork + i - 1);
	if (check_sb_dead(philo->setting))
		return (pthread_mutex_unlock(philo->setting->mtx_fork + i - 1), 1);
	print_message(philo->setting, i, FORK);
	if (num_phils == 1)
	{
		pthread_mutex_unlock(philo->setting->mtx_fork + i - 1);
		return (usleep(philo->setting->time_to_die * 1000), 1);
	}
	pthread_mutex_lock(philo->setting->mtx_fork + i % num_phils);
	if (check_sb_dead(philo->setting))
	{
		pthread_mutex_unlock(philo->setting->mtx_fork + i - 1);
		pthread_mutex_unlock(philo->setting->mtx_fork + i % num_phils);
		return (1);
	}
	eating(philo);
	pthread_mutex_unlock(philo->setting->mtx_fork + i - 1);
	pthread_mutex_unlock(philo->setting->mtx_fork + i % num_phils);
	return (0);
}

void	sleeping(t_philo *philo)
{
	int	i;

	i = philo->id + 1;
	print_message(philo->setting, i, SLEEPING);
	usleep(philo->setting->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	thinking(t_philo *philo)
{
	int	i;

	i = philo->id + 1;
	print_message(philo->setting, i, THINKING);
	philo->status = EATING;
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
