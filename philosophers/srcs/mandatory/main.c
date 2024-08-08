/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/08 15:28:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	show_struct(t_phil *phil)
// {
// 	printf("num_of_phils :%d\n", phil->num_of_phils);
// 	printf("time_to_die :%lu\n", phil->time_to_die);
// 	printf("time_to_die :%lu\n", phil->time_to_die);
// 	printf("time_to_sleep :%lu\n", phil->time_to_sleep);
// 	printf("must_eat_times :%d\n", phil->must_eat_times);
// }

int	eating_with_fork(t_philo *philo)
{
	int	i;

	i = philo->id;
	pthread_mutex_lock(philo->setting->mutexFork + i);
	printf("%05lu %2d has taken a fork\n", get_time_diff(&philo->setting->start_time), i);
	pthread_mutex_lock(philo->setting->mutexFork + (i + 1) % philo->setting->num_of_phils);
	if (get_time_diff(&philo->beg_lastmeal) > philo->setting->time_to_die)
	{
		pthread_mutex_unlock(philo->setting->mutexFork + i);
		pthread_mutex_unlock(philo->setting->mutexFork + (i + 1) % philo->setting->num_of_phils);
		return(1);
	}
	printf("%05lu %2d has taken a fork\n", get_time_diff(&philo->setting->start_time), i);
	printf("%05lu %2d is eating\n", get_time_diff(&philo->setting->start_time), philo->id);
	gettimeofday(&philo->beg_lastmeal, NULL);
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
	while (1)
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
		// printf("%d time diff %lu\n", philo->id, get_time_diff(&philo->beg_lastmeal));
		if (get_time_diff(&philo->beg_lastmeal) > philo->setting->time_to_die)
			break ;
		if (philo->setting->must_eat_times
			&& philo->num_meals >= philo->setting->must_eat_times)
			break ;
	}
	printf("%05lu %2d died\n", get_time_diff(&philo->setting->start_time), philo->id);
	free(arg); //If detached, need to free arg before thread terminates
	// return (arg);
	return (NULL);
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
		// detach right after thread creation
		if (pthread_detach(th[i]))
		{
			printf("Failed to detadch thread %d\n", i);
			return (3);
		}
		i++;
	}
	return (0);
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	unsigned int		i;
	int					ret;
	// t_philo				*body;

	i = 0;
	// while (i < setting->num_of_phils)
	// {
	// 	if (pthread_join(th[i], (void **)&body))
	// 	{
	// 		printf("Failed to join thread %d\n", i);
	// 		return ;
	// 	}
	// 	free(body);
	// 	i++;
	// }
	while (1)
	{
		i = 0;
		while(i < setting->num_of_phils)
		{
			ret = pthread_join(th[i], NULL);
			// printf("ret is %d\n", ret);
			if (ret == 0 || ret == ESRCH)
				return ;
			i++;
		}
		usleep(500);
	}
}

// void	detach_thread(t_setup *setting, pthread_t *th)
// {
// 	unsigned int		i;
	
// 	i = 0;
// 	while (i < setting->num_of_phils)
// 	{
// 		if (pthread_detach(th[i]))
// 		{
// 			printf("Failed to detach thread %d\n", i);
// 			return ;
// 		}
// 		i++;
// 	}
// }

int	main(int ac, char *av[])
{
	t_setup		setting;
	pthread_t	*th;
	pthread_mutex_t	*mutexFork;

	if (ac_check(ac))
		return (1);
	if (input_check(ac, av, &setting))
		return (1);
	th = malloc((setting.num_of_phils) * sizeof(pthread_t));
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
	free(th);
	return (0);
}
