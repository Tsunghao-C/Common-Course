/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/08 18:32:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_with_fork(t_philo *philo)
{
	int	i;

	i = philo->id;
	pthread_mutex_lock(philo->setting->mutexFork + i);
	if (philo->setting->died)
		return (1);
	printf("%05lu %2d has taken a fork\n", get_time_diff(&philo->setting->start_time), i);
	pthread_mutex_lock(philo->setting->mutexFork + (i + 1) % philo->setting->num_of_phils);
	if (philo->setting->died)
		return (1);
	printf("%05lu %2d has taken a fork\n", get_time_diff(&philo->setting->start_time), i);
	printf("%05lu %2d is eating\n", get_time_diff(&philo->setting->start_time), philo->id);
	gettimeofday(philo->setting->last_meal + i, NULL);
	usleep(philo->setting->time_to_eat * 1000);
	philo->num_meals += 1;
	pthread_mutex_unlock(philo->setting->mutexFork + i);
	pthread_mutex_unlock(philo->setting->mutexFork + (i + 1) % philo->setting->num_of_phils);
	philo->status = SLEEPING;
	return (0);
}

void	sleeping(t_philo *philo)
{
	printf("%05lu %2d is sleeping\n", get_time_diff(&philo->setting->start_time), philo->id);
	usleep(philo->setting->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	*life_of_philo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(philo->setting->time_to_eat * 500);
	while (!philo->setting->died)
	{
		if (philo->status == THINKING)
		{
			printf("%05lu %2d is thinking\n", get_time_diff(&philo->setting->start_time), philo->id);
			philo->status = EATING;
		}
		else if (philo->status == EATING)
		{
			if (eating_with_fork(philo))
				break ;
		}
		else if (philo->status == SLEEPING)
			sleeping(philo);
		if (philo->setting->must_eat_times
			&& philo->num_meals >= philo->setting->must_eat_times)
			philo->setting->died = 1;
	}
	return (NULL);
}

void	*starvation_check(void *arg)
{
	t_setup				*setting;
	unsigned int		i;

	setting = (t_setup *)arg;
	while (!setting->died)
	{
		i = 0;
		while (i < setting->num_of_phils)
		{
			if (get_time_diff(setting->last_meal + i) > setting->time_to_die)
			{
				setting->died = 1;
				printf("%05lu %2d died\n", get_time_diff(&setting->start_time), i);
				break ;
			}
			i++;
		}
	}
	return (arg);
}

int	init_thread(t_setup *setting, pthread_t *th)
{
	unsigned int	i;
	t_philo			*phil;

	i = 0;
	while (i < setting->num_of_phils)
	{
		phil = malloc(sizeof(t_philo));
		if (!phil)
			return (1);
		init_phil(phil, i, setting);
		if (pthread_create(th + i, NULL, &life_of_philo, phil))
		{
			printf("Failed to create thread %d\n", i);
			return (2);
		}
		i++;
	}
	if (pthread_create(th + i, NULL, &starvation_check, setting))
		return (4);
	return (0);
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	unsigned int		i;
	t_philo				*body;

	i = 0;
	while (i < setting->num_of_phils)
	{
		if (pthread_join(th[i], (void **)&body))
		{
			printf("Failed to join thread %d\n", i);
			return ;
		}
		free(body);
		i++;
	}
	pthread_join(th[i], NULL);
}

int	main(int ac, char *av[])
{
	t_setup		setting;
	pthread_t	*th;
	pthread_mutex_t	*mutexFork;

	if (ac_check(ac))
		return (1);
	if (input_check(ac, av, &setting))
		return (1);
	th = malloc((setting.num_of_phils + 1) * sizeof(pthread_t));
	if (!th)
		return (2);
	mutexFork = malloc((setting.num_of_phils) * sizeof(pthread_mutex_t));
	if (!mutexFork)
		return (free(th), 2);
	init_mutex(&setting, mutexFork);
	if (init_thread(&setting, th))
		return (free(th), destroy_mutex(&setting, mutexFork), 3);
	join_thread(&setting, th);
	destroy_mutex(&setting, mutexFork);
	free(setting.last_meal);
	free(th);
	return (0);
}
