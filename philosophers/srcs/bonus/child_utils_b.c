/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:24:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 20:29:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	do_philos(t_setup *setting)
{
	int	i;

	i = 0;
	while (i < setting->phils)
	{
		setting->philos[i] = fork();
		if (setting->philos[i] == -1)
		{
			destroy_setting(setting);
			exit(EXIT_FAILURE);
		}
		else if (!setting->philos[i])
			start_philo(i, setting);
		i++;
	}
}

void	start_philo(int id, t_setup *setting)
{
	pthread_t	th;
	t_philo		philo;

	init_philo(id, setting, &philo);
	if (pthread_create(&th, NULL, &starvation_check, &philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(th))
	{
		write(ER, "Failed to detach a thread\n", 27);
		exit(EXIT_FAILURE);
	}
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

void	init_philo(int id, t_setup *setting, t_philo *philo)
{
	philo->id = id + 1;
	philo->status = THINKING;
	philo->num_meals = 0;
	philo->is_full = 0;
	philo->last_meal = setting->start;
	philo->setting = setting;
}
