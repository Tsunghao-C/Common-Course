/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_activity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:08:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/10 19:45:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_full(t_philo *philo)
{
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
}

static void	eating(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("%05u %2d has taken a fork\n", get_time(&philo->setting->start), i + 1);
	printf("%05u %2d is eating\n", get_time(&philo->setting->start), i + 1);
	pthread_mutex_lock(philo->setting->mtx_meal);
	gettimeofday(philo->setting->last_meal + i, NULL);
	pthread_mutex_unlock(philo->setting->mtx_meal);
	usleep(philo->setting->time_to_eat * 1000);
	check_full(philo);
}

int	eating_with_forks(t_philo *philo)
{
	int			i;
	__uint16_t	num_phils;

	i = philo->id;
	num_phils = philo->setting->phils;
	pthread_mutex_lock(philo->setting->mtx_fork + i);
	if (check_sb_dead(philo->setting))
		return (pthread_mutex_unlock(philo->setting->mtx_fork + i), 1);
	printf("%05u %2d has taken a fork\n", get_time(&philo->setting->start), i + 1);
	if (num_phils == 1)
	{
		pthread_mutex_unlock(philo->setting->mtx_fork + i);
		return (usleep(philo->setting->time_to_die * 1100), 1);
	}
	pthread_mutex_lock(philo->setting->mtx_fork + (i + 1) % num_phils);
	if (check_sb_dead(philo->setting))
	{
		pthread_mutex_unlock(philo->setting->mtx_fork + i);
		pthread_mutex_unlock(philo->setting->mtx_fork + (i + 1) % num_phils);
		return (1);
	}
	eating(philo);
	pthread_mutex_unlock(philo->setting->mtx_fork + i);
	pthread_mutex_unlock(philo->setting->mtx_fork + (i + 1) % num_phils);
	return (0);
}

void	sleeping(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("%05u %2d is sleeping\n", get_time(&philo->setting->start), i + 1);
	usleep(philo->setting->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	thinking(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("%05u %2d is thinking\n", get_time(&philo->setting->start), i + 1);
	philo->status = EATING;
}
