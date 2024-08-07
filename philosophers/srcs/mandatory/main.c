/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 13:27:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_usec);
}

static int	input_check(int ac, char *av[], t_setup *setting)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
			return (1);
	}
	setting->num_of_phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]) * 1000;
	setting->time_to_eat = ft_atol(av[3]) * 1000;
	setting->time_to_sleep = ft_atol(av[4]) * 1000;
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	setting->start_time = get_time();
	return (0);
}

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
			printf("%lu philo %d is thinking\n", (get_time() - philo->setting->start_time) / 1000, philo->id);
			philo->status = EATING;
		}
		else if (philo->status == EATING)
		{
			//lock
			//try to eat
			printf("%lu philo %d is eating\n", (get_time() - philo->setting->start_time) / 1000, philo->id);
			philo->num_meals += 1;
			philo->beg_lastmeal = get_time();
			usleep(philo->setting->time_to_eat);
			//unlock
			philo->status = SLEEPING;
		}
		else
		{
			printf("%lu philo %d is sleeping\n", (get_time() - philo->setting->start_time) / 1000, philo->id);
			usleep(philo->setting->time_to_sleep);
			philo->status = THINKING;
		}
		if (get_time() - philo->beg_lastmeal > philo->setting->time_to_die)
			break ;
	}
	printf("%lu philo %d died\n", (get_time() - philo->setting->start_time) / 1000, philo->id);
	return (arg);
}

void	init_phil(t_philo *phil, int i, t_setup *setting)
{
	phil->id = i;
	phil->status = THINKING;
	phil->beg_lastmeal = setting->start_time;
	phil->num_meals = 0;
	phil->setting = setting;
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
			perror("Failed to create thread");
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
			perror("Failed to join thread");
		free(body);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_setup		setting;
	pthread_t	*th;

	th = NULL;
	if (ac < 5 || ac > 6)
	{
		write(ER, "Need 4 or 5 args in the following order:\n", 41);
		write(ER, "num_of_phils time_to_die time_to_eat ", 37);
		write(ER, "time_to_sleep [optional]must_eat_times\n", 39);
		return (1);
	}
	if (input_check(ac, av, &setting))
	{
		write(ER, "Wrong input. Must be positive numbers\n", 38);
		return (1);
	}
	printf("Start philosophers!\n");
	th = malloc((setting.num_of_phils + 1) * sizeof(pthread_t));
	if (!th)
		return (2);
	init_thread(&setting, th);
	join_thread(&setting, th);
	free(th);
	return (0);
}
