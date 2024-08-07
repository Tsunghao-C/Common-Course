/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:10:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 18:37:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time_diff(struct timeval *ref)
{
	struct timeval  current;
    unsigned long   diff;

    gettimeofday(&current, NULL);
    diff = (current.tv_sec - ref->tv_sec) * 1000;
    diff += (current.tv_usec - ref->tv_usec) / 1000;
	return (diff);
}

void	init_phil(t_philo *phil, int i, t_setup *setting)
{
	phil->id = i;
	phil->status = THINKING;
	phil->beg_lastmeal = setting->start_time;
	phil->num_meals = 0;
	phil->setting = setting;
}

int	input_check(int ac, char *av[], t_setup *setting)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
        {
            write(ER, "Wrong input. Must be positive numbers\n", 38);
            return (1);
        }
	}
	setting->num_of_phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]);
	setting->time_to_eat = ft_atol(av[3]);
	setting->time_to_sleep = ft_atol(av[4]);
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	gettimeofday(&setting->start_time, NULL);
    setting->mutexFork = NULL;
	return (0);
}

void    init_mutex(t_setup *setting, pthread_mutex_t *mutexFork)
{
    unsigned int i;

    i = 0;
    while (i < setting->num_of_phils)
    {
        pthread_mutex_init(mutexFork + i, NULL);
        i++;
    }
    setting->mutexFork = mutexFork;
}

void	destroy_mutex(t_setup *setting, pthread_mutex_t *mutexFork)
{
    unsigned int i;

    i = 0;
    while (i <setting->num_of_phils)
    {
        pthread_mutex_destroy(mutexFork + i);
        i++;
    }
    free(mutexFork);
}
