/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:34:42 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 20:27:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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

void	err_exit_main(t_setup *setting)
{
	int	i;

	i = 0;
	write(ER, "Failed to create checker thread\n", 33);
	while (i < setting->phils)
	{
		if (setting->philos[i])
			kill(setting->philos[i], SIGTERM);
		i++;
	}
	destroy_setting(setting);
	exit(EXIT_FAILURE);
}

void	*check_sb_dead(void *arg)
{
	t_setup	*setting;
	int		i;

	setting = (t_setup *)arg;
	i = 0;
	sem_wait(setting->dead);
	while (i < setting->phils)
	{
		if (setting->philos[i])
			kill(setting->philos[i], SIGTERM);
		sem_post(setting->full);
		i++;
	}
	return (NULL);
}

void	*check_all_fulled(void *arg)
{
	t_setup			*setting;
	__uint16_t		fulled_philos;

	setting = (t_setup *)arg;
	fulled_philos = 0;
	while (fulled_philos < setting->phils)
	{
		sem_wait(setting->full);
		fulled_philos += 1;
	}
	sem_post(setting->dead);
	return (NULL);
}
