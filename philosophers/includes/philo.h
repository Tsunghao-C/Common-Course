/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/10 15:11:43 by tsuchen          ###   ########.fr       */
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
	__uint16_t		phils;
	__uint32_t		time_to_die;
	__uint32_t		time_to_eat;
	__uint32_t		time_to_sleep;
	__uint16_t		must_eat_times;
	struct timeval	start;
	struct timeval	*last_meal;
	pthread_mutex_t	*mtx_fork;
	pthread_mutex_t	*mtx_full;
	int				died;
	__uint16_t		fulled_phils;
}	t_setup;

typedef struct s_philo
{
	int				id;
	t_task			status;
	__uint16_t		num_meals;
	int				is_full;
	t_setup			*setting;
}	t_philo;

/* utils libft functions */
long		ft_atol(const char *nptr);
/* utils functions */
__uint32_t	get_time(struct timeval *ref);
void		init_phil(t_philo *phil, int i, t_setup *setting);
int			input_check(int ac, char *av[], t_setup *setting);
void		init_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
				pthread_mutex_t *mtx_full);
void		destroy_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
				pthread_mutex_t *mtx_full);
/* error functions */
int			ac_check(int ac);
/* activity functions */
int			eating_with_fork(t_philo *philo);
void		check_full(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

#endif
