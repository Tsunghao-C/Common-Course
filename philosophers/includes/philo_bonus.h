/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/12 12:52:54 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include <semaphore.h>
# include <fcntl.h>

# define ER STDERR_FILENO
# define SEM_FORKS "sem_forks"
# define SEM_DEAD "sem_dead"
# define SEM_FULL "sem_full"

typedef enum e_task
{
	THINKING,
	EATING,
	SLEEPING,
	FORK,
	DIED
}	t_task;

typedef struct s_setup
{
	__uint16_t		phils;
	__uint32_t		time_to_die;
	__uint32_t		time_to_eat;
	__uint32_t		time_to_sleep;
	__uint16_t		must_eat_times;
	struct timeval	start;
	sem_t			*forks;
	sem_t			*dead;
	sem_t			*full;
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
int			input_check(int ac, char *av[]);
__uint32_t	get_time(struct timeval *ref);
int			init_setting(int ac, char *av[], t_setup *setting);
int			destroy_setting(t_setup *setting);
/* error functions */
int			check_all_full(t_setup *setting);
int			check_starved_time(int id, t_setup *setting);
int			check_sb_dead(t_setup *setting);
void		turn_dead(t_setup *setting);
/* activity functions */
int			eating_with_forks(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		print_message(t_setup *setting, int id, t_task action);

#endif
