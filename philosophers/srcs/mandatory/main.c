/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/06 18:56:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	input_check(int ac, char *av[], t_phil *phil)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
			return (1);
	}
	phil->num_of_phils = ft_atol(av[1]);
	phil->time_to_die = ft_atol(av[2]);
	phil->time_to_eat = ft_atol(av[3]);
	phil->time_to_sleep = ft_atol(av[4]);
	phil->must_eat_times = 0;
	if (ac == 6)
		phil->must_eat_times = ft_atol(av[5]);
	return (0);
}

void	show_struct(t_phil *phil)
{
	printf("num_of_phils :%d\n", phil->num_of_phils);
	printf("time_to_die :%lu\n", phil->time_to_die);
	printf("time_to_die :%lu\n", phil->time_to_die);
	printf("time_to_sleep :%lu\n", phil->time_to_sleep);
	printf("must_eat_times :%d\n", phil->must_eat_times);
}

int	main(int ac, char *av[])
{
	t_phil	phil;

	if (ac < 5 || ac > 6)
	{
		write(ER, "Need 4 or 5 args in the following order:\n", 41);
		write(ER, "num_of_phils time_to_die time_to_eat ", 37);
		write(ER, "time_to_sleep [optional]must_eat_times\n", 39);
		return (1);
	}
	if (input_check(ac, av, &phil))
	{
		write(ER, "Wrong input. Must be positive numbers\n", 38);
		return (1);
	}
	printf("Start philosophers!\n");
	show_struct(&phil);
	return (0);
}
