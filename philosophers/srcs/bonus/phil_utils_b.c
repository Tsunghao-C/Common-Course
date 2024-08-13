/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:55:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 18:47:59 by tsuchen          ###   ########.fr       */
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

static int	destroy_sem(sem_t *sem, const char *file_name)
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

void	init_philo(int id, t_setup *setting, t_philo *philo)
{
	philo->id = id + 1;
	philo->status = THINKING;
	philo->num_meals = 0;
	philo->is_full = 0;
	philo->last_meal = setting->start;
	philo->setting = setting;
}

void	start_philo(int id, t_setup *setting)
{
	pthread_t	th;
	t_philo		philo;

	init_philo(id, setting, &philo);
	if (pthread_create(&th, NULL, &starvation_check, &philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(th))
		err_exit_detach();
	if (id % 2)
		ft_usleep(setting->time_to_eat / 2, setting);
	while (1)
	{
		if (philo.status == THINKING)
			thinking(&philo);
		else if (philo.status == EATING)
			eating_with_forks(&philo);
		else if (philo.status == SLEEPING)
			sleeping(&philo);
	}
	exit(EXIT_SUCCESS);
}

void	do_philos(t_setup *setting)
{
	int	i;

	i = 0;
	while (i < setting->phils)
	{
		setting->philos[i] = fork();
		if (setting->philos[i] == -1)
			err_exit_fork(setting);
		else if (!setting->philos[i])
			start_philo(i, setting);
		i++;
	}
}
