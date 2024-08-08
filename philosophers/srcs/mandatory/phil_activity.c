/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_activity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:08:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/08 19:37:44 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_with_fork(t_philo *philo)
{
	int				i;
	unsigned int	num_phils;

	i = philo->id;
	num_phils = philo->setting->phils;
	pthread_mutex_lock(philo->setting->mtx_fork + i);
	if (philo->setting->died)
		return (1);
	printf("%05u %2d has taken a fork\n", get_time(&philo->setting->start), i);
	pthread_mutex_lock(philo->setting->mtx_fork + (i + 1) % num_phils);
	if (philo->setting->died)
		return (1);
	printf("%05u %2d has taken a fork\n", get_time(&philo->setting->start), i);
	printf("%05u %2d is eating\n", get_time(&philo->setting->start), i);
	gettimeofday(philo->setting->last_meal + i, NULL);
	usleep(philo->setting->time_to_eat * 1000);
	philo->num_meals += 1;
	pthread_mutex_unlock(philo->setting->mtx_fork + i);
	pthread_mutex_unlock(philo->setting->mtx_fork + (i + 1) % num_phils);
	philo->status = SLEEPING;
	return (0);
}

void	sleeping(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("%05u %2d is sleeping\n", get_time(&philo->setting->start), i);
	usleep(philo->setting->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	thinking(t_philo *philo)
{
	int	i;

	i = philo->id;
	printf("%05u %2d is thinking\n", get_time(&philo->setting->start), i);
	philo->status = EATING;
}
