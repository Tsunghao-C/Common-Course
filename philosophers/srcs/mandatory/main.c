/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 17:34:29 by tsuchen          ###   ########.fr       */
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

void	*life_of_philo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->status == THINKING)
		{
			printf("%lu philo %d is thinking\n", get_time_diff(&philo->setting->start_time), philo->id);
			philo->status = EATING;
		}
		else if (philo->status == EATING)
		{
			//lock
			//try to eat
			printf("%lu philo %d is eating\n", get_time_diff(&philo->setting->start_time), philo->id);
			philo->num_meals += 1;
			gettimeofday(&philo->beg_lastmeal, NULL);
			// philo->beg_lastmeal = get_time();
			usleep(philo->setting->time_to_eat * 1000);
			//unlock
			philo->status = SLEEPING;
		}
		else if (philo->status == SLEEPING)
		{
			printf("%lu philo %d is sleeping\n", get_time_diff(&philo->setting->start_time), philo->id);
			usleep(philo->setting->time_to_sleep * 1000);
			philo->status = THINKING;
		}
		if (get_time_diff(&philo->beg_lastmeal)> philo->setting->time_to_die)
			break ;
	}
	printf("%lu philo %d died\n", get_time_diff(&philo->setting->start_time), philo->id);
	return (arg);
}

void	init_thread(t_setup *setting, pthread_t *th)
{
	unsigned int	i;
	t_philo			*phil;

	i = 0;
	while (i < setting->num_of_phils)
	{
		phil = malloc(sizeof(t_philo));
		if (!phil)
			return ;
		init_phil(phil, i, setting);
		if (pthread_create(th + i, NULL, &life_of_philo, phil))
			return ;
		i++;
	}
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	unsigned int		i;
	t_philo				*body;

	i = 0;
	while (i < setting->num_of_phils)
	{
		if (pthread_join(th[i], (void **)&body))
			return ;
		free(body);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_setup		setting;
	pthread_t	*th;

	th = NULL;
	if (ac_check(ac))
		return (1);
	if (input_check(ac, av, &setting))
		return (1);
	printf("Start philosophers!\n");
	th = malloc((setting.num_of_phils) * sizeof(pthread_t));
	if (!th)
		return (2);
	init_thread(&setting, th);
	join_thread(&setting, th);
	free(th);
	return (0);
}
