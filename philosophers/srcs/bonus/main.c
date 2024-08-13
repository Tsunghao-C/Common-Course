/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 20:26:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_checker_thread(t_setup *setting, pthread_t th[2])
{
	if (pthread_create(th, NULL, &check_sb_dead, setting))
		return (1);
	if (pthread_create(th + 1, NULL, &check_all_fulled, setting))
		return (2);
	if (pthread_detach(th[1]))
		return (3);
	return (0);
}

void	wait_all(t_setup *setting)
{
	int	i;

	i = 0;
	while (i < setting->phils)
	{
		if (setting->philos[i])
			waitpid(setting->philos[i], NULL, 0);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_setup		setting;
	pthread_t	th[2];

	if (input_check(ac, av))
		return (1);
	if (init_setting(ac, av, &setting))
		return (2);
	do_philos(&setting);
	if (init_checker_thread(&setting, th))
		err_exit_main(&setting);
	if (pthread_join(th[0], NULL))
		write(ER, "Failed to join kill thread\n", 28);
	wait_all(&setting);
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
