/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/11 21:17:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*life_of_philo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(philo->setting->time_to_eat * 500);
	while (1)
	{
		if (check_sb_dead(philo->setting))
			break ;
		if (philo->status == THINKING)
			thinking(philo);
		else if (philo->status == EATING)
		{
			if (eating_with_forks(philo))
				break ;
			philo->status = SLEEPING;
		}
		else if (philo->status == SLEEPING)
			sleeping(philo);
	}
	free(philo);
	return (NULL);
}

void	*starvation_check(void *arg)
{
	t_setup			*setting;
	__uint16_t		i;

	setting = (t_setup *)arg;
	usleep(setting->time_to_eat * 500);
	while (1)
	{
		if (check_sb_dead(setting))
			break ;
		i = 0;
		while (i < setting->phils)
		{
			if (check_starved_time(i, setting))
			{
				turn_dead(setting);
				return (NULL);
			}
			i++;
		}
		if (check_all_full(setting))
			turn_dead(setting);
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
			return (2);
		i++;
	}
	if (pthread_create(th + i, NULL, &starvation_check, setting))
		return (2);
	return (0);
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	__uint16_t		i;

	i = 0;
	while (i < setting->phils + 1)
	{
		if (pthread_join(th[i], NULL))
			return ;
		i++;
	}
	free(th);
}

void	check_dead(void *arg)
{
	// in each philo process, use sem_post(dead) if he dies
	// sem_wait(arg->dead);
	// kill every other processes
}

void	check_fulled(void *arg)
{
	// in each philo process, use sem_post(full) if he is fulled.
	int	fulled_philos;

	fulled_philos = 0;
	while (fulled_philos < total_philos)
	{
		// sem_wait(arg->full);
		// fulled_philos += 1;
	}
	// sem_post(arg->dead);
}

int	main(int ac, char *av[])
{
	t_setup	setting;
	sem_t	*forks;
	sem_t	*dead;
	sem_t	*full;
	int		i;

	if (input_check(ac, av))
		return (1);
	init_setting(ac, av, &setting);
		return (2);
	// Open semaphores
	forks = sem_open(SEM_FORKS, O_CREAT, 0644, 1);
	dead = sem_open(SEM_DEAD, O_CREAT, 0644, 1);
	full = sem_open(SEM_FULL, O_CREAT, 0644, 1);
	// Initialize semaphores
	i = 0;
	while (i < setting.phils)
	{
		sem_post(forks);
		sem_post(full);
		i++;
	}
	return (0);
}

// void	show_setting(t_setup *set)
// {
// 	printf("phils %d\n", set->phils);
// 	printf("time to die %u\n", set->time_to_die);
// 	printf("time to eat %u\n", set->time_to_eat);
// 	printf("time to sleep %u\n", set->time_to_sleep);
// 	printf("must_eat_times %d\n", set->must_eat_times);
// 	printf("died %d\n", set->died);
// 	printf("fulled_phils %d\n", set->fulled_phils);
// 	printf("start sec %ld, usec %d\n", set->start.tv_sec, set->start.tv_usec);
// 	printf("current time %u\n", get_time(&set->start));
// }
