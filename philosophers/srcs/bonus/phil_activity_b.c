/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_activity_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:09:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 19:09:59 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*starvation_check(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->setting->meal);
		if (get_time(&philo->last_meal) > philo->setting->time_to_die)
		{
			print_message(philo->setting, philo->id, DIED);
			sem_post(philo->setting->dead);
			return (NULL);
		}
		sem_post(philo->setting->meal);
	}
	return (NULL);
}

void	eating_with_forks(t_philo *philo)
{
	sem_wait(philo->setting->forks);
	print_message(philo->setting, philo->id, FORK);
	sem_wait(philo->setting->forks);
	print_message(philo->setting, philo->id, FORK);
	sem_wait(philo->setting->meal);
	gettimeofday(&philo->last_meal, NULL);
	sem_post(philo->setting->meal);
	print_message(philo->setting, philo->id, EATING);
	philo->num_meals += 1;
	if (philo->setting->must_eat_times && !philo->is_full)
	{
		if (philo->num_meals >= philo->setting->must_eat_times)
		{
			sem_post(philo->setting->full);
			philo->is_full = 1;
		}
	}
	ft_usleep(philo->setting->time_to_eat, philo->setting);
	sem_post(philo->setting->forks);
	sem_post(philo->setting->forks);
	philo->status = SLEEPING;
}

void	sleeping(t_philo *philo)
{
	print_message(philo->setting, philo->id, SLEEPING);
	ft_usleep(philo->setting->time_to_sleep, philo->setting);
	philo->status = THINKING;
}

void	thinking(t_philo *philo)
{
	print_message(philo->setting, philo->id, THINKING);
	if (philo->setting->phils % 2)
		ft_usleep(philo->setting->time_to_eat / 2, philo->setting);
	philo->status = EATING;
}

void	print_message(t_setup *setting, int id, t_task action)
{
	sem_wait(setting->print);
	if (action == THINKING)
		printf("%05u %2d is thinking\n", get_time(&setting->start), id);
	else if (action == EATING)
		printf("%05u %2d is eating\n", get_time(&setting->start), id);
	else if (action == SLEEPING)
		printf("%05u %2d is sleeping\n", get_time(&setting->start), id);
	else if (action == FORK)
		printf("%05u %2d has taken a fork\n", get_time(&setting->start), id);
	else if (action == DIED)
	{
		printf("%05u %2d died\n", get_time(&setting->start), id);
		return ;
	}
	sem_post(setting->print);
}
