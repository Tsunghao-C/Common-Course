/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 21:26:58 by tsuchen          ###   ########.fr       */
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
	SLEEPING,
	FORK,
	DIED
}	t_task;

typedef enum e_mtx
{
	FULL,
	DEAD,
	MEAL,
	PRINT
}	t_mtx;

typedef struct s_setup
{
	__uint16_t		phils;
	__uint32_t		time_to_die;
	__uint32_t		time_to_eat;
	__uint32_t		time_to_sleep;
	__uint16_t		must_eat_times;
	struct timeval	start;
	int				died;
	__uint16_t		fulled_phils;
	struct timeval	*last_meal;
	pthread_mutex_t	*mtx_fork;
	pthread_mutex_t	*mtx_full;
	pthread_mutex_t	*mtx_dead;
	pthread_mutex_t	*mtx_meal;
	pthread_mutex_t	*mtx_print;
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
void		ft_usleep(__uint32_t time, t_setup *setting);
int			init_setting(int ac, char *av[], t_setup *setting);
void		init_phil(t_philo *phil, int i, t_setup *setting);
void		init_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
				pthread_mutex_t mtx[4]);
void		destroy_mutex(t_setup *setting, pthread_mutex_t *mtx_fork,
				pthread_mutex_t mtx[4]);
/* error functions */
int			input_check(int ac, char *av[]);
int			check_all_full(t_setup *setting);
int			check_starved_time(int id, t_setup *setting);
int			check_sb_dead(t_setup *setting);
void		turn_dead(t_setup *setting);
/* activity functions */
int			eating_with_forks(t_philo *philo);
int			eating_with_forks_right(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		print_message(t_setup *setting, int id, t_task action);

#endif
