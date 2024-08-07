/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 18:06:46 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

# define ER STDERR_FILENO

typedef enum e_task
{
	THINKING,
	EATING,
	SLEEPING
}	t_task;

typedef struct s_setup
{
	unsigned int	num_of_phils;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned int	must_eat_times;
	struct timeval	start_time;
	pthread_mutex_t	*mutexFork;
}	t_setup;

typedef struct s_philo
{
	int				id;
	t_task			status;
	struct timeval	beg_lastmeal;
	unsigned int	num_meals;
	t_setup			*setting;
}	t_philo;

/* utils libft functions */
long	ft_atol(const char *nptr);
/* utils functions */
unsigned long	get_time_diff(struct timeval *ref);
void	init_phil(t_philo *phil, int i, t_setup *setting);
int		input_check(int ac, char *av[], t_setup *setting);
void    init_mutex(t_setup *setting, pthread_mutex_t *mutexFork);
void	destroy_mutex(t_setup *setting, pthread_mutex_t *mutexFork);
/* error functions */
int		ac_check(int ac);

#endif
