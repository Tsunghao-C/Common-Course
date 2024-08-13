/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:55:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 19:51:49 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sem(t_setup *setting)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_DEAD);
	sem_unlink(SEM_FULL);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_PRINT);
	setting->forks = sem_open(SEM_FORKS, O_CREAT, 0644, setting->phils);
	if (setting->forks == SEM_FAILED)
		return (1);
	setting->dead = sem_open(SEM_DEAD, O_CREAT, 0644, 0);
	if (setting->dead == SEM_FAILED)
		return (2);
	setting->full = sem_open(SEM_FULL, O_CREAT, 0644, 0);
	if (setting->full == SEM_FAILED)
		return (3);
	setting->meal = sem_open(SEM_MEAL, O_CREAT, 0644, 1);
	if (setting->meal == SEM_FAILED)
		return (4);
	setting->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (setting->print == SEM_FAILED)
		return (5);
	return (0);
}

int	destroy_sem(sem_t *sem, const char *file_name)
{
	if (sem_close(sem))
		return (1);
	if (sem_unlink(file_name))
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
	memset(setting->philos, -1, MAX_PHILO);
	setting->forks = NULL;
	setting->dead = NULL;
	setting->full = NULL;
	setting->meal = NULL;
	setting->print = NULL;
	if (init_sem(setting))
	{
		destroy_setting(setting);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	destroy_setting(t_setup *setting)
{
	if (setting->forks != SEM_FAILED && destroy_sem(setting->forks, SEM_FORKS))
		write(ER, "Failed to destroy sem_fork\n", 28);
	if (setting->dead != SEM_FAILED && destroy_sem(setting->dead, SEM_DEAD))
		write(ER, "Failed to destroy sem_dead\n", 28);
	if (setting->full != SEM_FAILED && destroy_sem(setting->full, SEM_FULL))
		write(ER, "Failed to destroy sem_full\n", 28);
	if (setting->meal != SEM_FAILED && destroy_sem(setting->meal, SEM_MEAL))
		write(ER, "Failed to destroy sem_meal\n", 28);
	if (setting->print != SEM_FAILED && destroy_sem(setting->print, SEM_PRINT))
		write(ER, "Failed to destroy sem_print\n", 29);
}
