/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/10 15:09:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_of_philo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(philo->setting->time_to_eat * 500);
	while (!philo->setting->died)
	{
		if (philo->status == THINKING)
			thinking(philo);
		else if (philo->status == EATING)
		{
			if (eating_with_fork(philo))
				break ;
		}
		else if (philo->status == SLEEPING)
			sleeping(philo);
	}
	return (arg);
}

void	*starvation_check(void *arg)
{
	t_setup			*setting;
	__uint16_t		i;

	setting = (t_setup *)arg;
	usleep(setting->time_to_eat * 500);
	while (!setting->died)
	{
		i = 0;
		while (i < setting->phils)
		{
			if (get_time(setting->last_meal + i) > setting->time_to_die)
			{
				setting->died = 1;
				printf("%05u %2d died\n", get_time(&setting->start), i);
				break ;
			}
			i++;
		}
		if (setting->fulled_phils == setting->phils)
			setting->died = 1;
	}
	return (NULL);
}

int	init_thread(t_setup *setting, pthread_t *th)
{
	__uint16_t	i;
	t_philo		*phil;

	i = 0;
	while (i < setting->phils)
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
	if (pthread_detach(th[i]))
	{
		printf("Failed to detach thread %d\n", i);
		return (3);
	}
	return (0);
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	__uint16_t		i;
	t_philo			*body;

	i = 0;
	while (i < setting->phils)
	{
		if (pthread_join(th[i], (void **)&body))
		{
			printf("Failed to join thread %d\n", i);
			return ;
		}
		free(body);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_setup			setting;
	pthread_t		*th;
	pthread_mutex_t	*mtx_fork;
	pthread_mutex_t	mtx_full;

	if (ac_check(ac))
		return (1);
	if (input_check(ac, av, &setting))
		return (1);
	th = malloc((setting.phils + 1) * sizeof(pthread_t));
	if (!th)
		return (2);
	mtx_fork = malloc((setting.phils) * sizeof(pthread_mutex_t));
	if (!mtx_fork)
		return (free(th), 2);
	init_mutex(&setting, mtx_fork, &mtx_full);
	if (init_thread(&setting, th))
		return (free(th), destroy_mutex(&setting, mtx_fork, &mtx_full), 3);
	join_thread(&setting, th);
	destroy_mutex(&setting, mtx_fork, &mtx_full);
	free(setting.last_meal);
	free(th);
	return (0);
}
