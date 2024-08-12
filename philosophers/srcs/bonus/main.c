/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 01:36:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_sb_dead(void *arg)
{
	t_setup	*setting;
	int		i;

	setting = (t_setup *)arg;
	i = 0;
	// in each philo process, use sem_post(dead) if he dies
	sem_wait(setting->dead);
	while (i < setting->phils)
	{
		if (setting->philos[i])
			kill(setting->philos[i], SIGTERM);
		i++;
	}
	return (NULL);
	// kill every other processes
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

int	main(int ac, char *av[])
{
	t_setup	setting;
	pthread_t	th[2];
	int			i;

	if (input_check(ac, av))
		return (1);
	if (init_setting(ac, av, &setting))
		return (2);
	// init checing threads
	if (pthread_create(th, NULL, &check_sb_dead, &setting))
		err_exit_main(&setting);
	if (pthread_create(th + 1, NULL, &check_all_fulled, &setting))
		err_exit_main(&setting);
	if (pthread_detach(th[1]))
		err_exit_main(&setting);
	// create philos with fork
	do_philos(&setting);
	if (pthread_join(th[0], NULL))
		write(ER, "Failed to join kill thread\n", 28);
	i = 0;
	while (i < setting.phils)
	{
		waitpid(setting.philos[i], NULL, 0);
		i++;
	}
	destroy_setting(&setting);
	return (0);
}

// void	show_setting(t_setup *set)
// {
// 	printf("phils %d\n", set->phils);
// 	printf("time to die %u\n", set->time_to_die);
// 	printf("time to eat %u\n", set->time_to_eat);
// 	printf("time to sleep %u\n", set->time_to_sleep);
// 	printf("must_eat_times %d\n", set->must_eat_times);
// 	printf("died %d\n", set->died);
// 	printf("fulled_phils %d\n", set->fulled_phils);
// 	printf("start sec %ld, usec %d\n", set->start.tv_sec, set->start.tv_usec);
// 	printf("current time %u\n", get_time(&set->start));
// }
