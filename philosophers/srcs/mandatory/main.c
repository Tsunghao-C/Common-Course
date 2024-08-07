/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 12:30:27 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	input_check(int ac, char *av[], t_setup *setting)
{
	int	i;
	struct timeval	start;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
			return (1);
	}
	setting->num_of_phils = ft_atol(av[1]);
	setting->time_to_die = ft_atol(av[2]);
	setting->time_to_eat = ft_atol(av[3]);
	setting->time_to_sleep = ft_atol(av[4]);
	setting->must_eat_times = 0;
	if (ac == 6)
		setting->must_eat_times = ft_atol(av[5]);
	gettimeofday(&start, NULL);
	setting->start_time = start.tv_usec;
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

void	*routine(void *arg)
{
	struct timeval	current_time;
	unsigned long	starve_time;

	gettimeofday(&current_time, NULL);
	starve_time = current_time.tv_usec - ((t_philo *)arg)->beg_lastmeal;
	printf("Philo %d starved for %lu\n", ((t_philo *)arg)->id, starve_time);
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
		if (pthread_create(th + i, NULL, &routine, phil))
			perror("Failed to create thread");
		i++;
	}
}

void	join_thread(t_setup *setting, pthread_t *th)
{
	unsigned int		i;
	t_philo				*body;
	struct timeval		current;

	i = 0;
	while (i < setting->num_of_phils)
	{
		if (pthread_join(th[i], (void **)&body))
			perror("Failed to join thread");
		gettimeofday(&current, NULL);
		printf("%lu philo %d died\n", current.tv_usec - setting->start_time, ((t_philo *)body)->id);
		free(body);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_setup		setting;
	//struct timeval	start;
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
