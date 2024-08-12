/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:55:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/12 12:54:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	input_check(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		write(ER, "Need 4 or 5 args in the following order:\n", 41);
		write(ER, "num_of_phils time_to_die time_to_eat ", 37);
		write(ER, "time_to_sleep [optional]must_eat_times\n", 39);
		return (1);
	}
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
		{
			write(ER, "Wrong input. Must be positive numbers\n", 38);
			return (2);
		}
	}
	return (0);
}

static int	init_sem(t_setup *setting)
{
	int i;

	// Open semaphores
	setting->forks = sem_open(SEM_FORKS, O_CREAT, 0644, 1);
	if (setting->forks == SEM_FAILED)
		return (1);
	setting->dead = sem_open(SEM_DEAD, O_CREAT, 0644, 1);
	if (setting->dead == SEM_FAILED)
		return (2);
	setting->full = sem_open(SEM_FULL, O_CREAT, 0644, 1);
	if (setting->dead == SEM_FAILED)
		return (3);
	// Initialize semaphores
	i = 0;
	while (i++ < setting->phils)
		sem_post(setting->forks);
	return (0);
}

static int	destroy_sem(sem_t *sem)
{
	if (sem_close(sem))
		return (1);
	if (sem_unlink(sem))
		return (2);
	return (0);
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
	setting->forks = NULL;
	setting->dead = NULL;
	setting->full = NULL;
	if (init_sem(setting))
	{
		destroy_setting(setting);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	destroy_setting(t_setup *setting)
{
	if (setting->forks != SEM_FAILED && destroy_sem(setting->forks))
		write(ER, "Failed to destroy sem_fork\n", 28);
	if (setting->dead != SEM_FAILED && destroy_sem(setting->dead))
		write(ER, "Failed to destroy sem_dead\n", 28);
	if (setting->full != SEM_FAILED && destroy_sem(setting->full))
		write(ER, "Failed to destroy sem_full\n", 28);
}
