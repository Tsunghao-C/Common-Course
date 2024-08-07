/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/07 12:16:12 by tsuchen          ###   ########.fr       */
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
	unsigned long	start_time;
}	t_setup;

typedef struct s_philo
{
	int				id;
	t_task			status;
	unsigned long	beg_lastmeal;
	unsigned int	num_meals;
	t_setup			*setting;
}	t_philo;

/* utils functions */
long	ft_atol(const char *nptr);

#endif
