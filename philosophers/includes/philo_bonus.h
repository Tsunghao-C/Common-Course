/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/14 01:56:36 by tsuchen          ###   ########.fr       */
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
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>

# define ER STDERR_FILENO
# define SEM_FORKS "sem_forks"
# define SEM_DEAD "sem_dead"
# define SEM_FULL "sem_full"
# define SEM_MEAL "sem_meal"
# define SEM_PRINT "sem_print"
# ifndef MAX_PHILO
#  define MAX_PHILO 200
# endif

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
	__uint32_t		time_to_think;
	__uint16_t		must_eat_times;
	struct timeval	start;
	pid_t			philos[MAX_PHILO];
	sem_t			*forks;
	sem_t			*dead;
	sem_t			*full;
	sem_t			*meal;
	sem_t			*print;
}	t_setup;

typedef struct s_philo
{
	int				id;
	t_task			status;
	__uint16_t		num_meals;
	int				is_full;
	struct timeval	last_meal;
	t_setup			*setting;
}	t_philo;

/* utils libft functions */
long		ft_atol(const char *nptr);
/* time functions */
__uint32_t	get_time(struct timeval *ref);
void		ft_usleep(__uint32_t time, t_setup *setting);
/* init setting and semaphore functions */
int			init_setting(int ac, char *av[], t_setup *set);
void		destroy_setting(t_setup *setting);
int			init_sem(t_setup *setting);
int			destroy_sem(sem_t *sem, const char *file_name);
int			init_checker_thread(t_setup *setting, pthread_t th[2]);
void		wait_all(t_setup *setting);
/* checker and error functions */
int			input_check(int ac, char *av[]);
void		err_exit_main(t_setup *setting);
void		*check_all_fulled(void *arg);
void		*check_sb_dead(void *arg);
/* activity functions */
void		*starvation_check(void *arg);
void		eating_with_forks(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		print_message(t_setup *setting, int id, t_task action);
/* child handling functions */
void		do_philos(t_setup *setting);
void		start_philo(int id, t_setup *setting);
void		init_philo(int id, t_setup *setting, t_philo *philo);

#endif
