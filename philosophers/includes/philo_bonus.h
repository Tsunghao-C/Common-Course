/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 00:59:09 by tsuchen          ###   ########.fr       */
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
# include <signal.h>

# define ER STDERR_FILENO
# define SEM_FORKS "sem_forks"
# define SEM_DEAD "sem_dead"
# define SEM_FULL "sem_full"
# define SEM_MEAL "sem_meal"
# define SEM_PRINT "sem_print"

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
	pid_t			*philos;
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
char		*ft_itoa(int n);
/* time functions */
__uint32_t	get_time(struct timeval *ref);
void		ft_usleep(__uint32_t time, t_setup *setting);
/* utils functions */
int			input_check(int ac, char *av[]);
int			init_setting(int ac, char *av[], t_setup *setting);
void		destroy_setting(t_setup *setting);
void		do_philos(t_setup *setting);
void		start_philo(int id, t_setup *setting);
void		init_philo(int id, t_setup *setting, t_philo *philo);
/* error functions */
void    	err_exit_fork(t_setup *setting);
void		err_exit_detach(void);
void		err_exit_main(t_setup *setting);
void		*check_all_fulled(void *arg);
void		*check_sb_dead(void *arg);
/* activity functions */
void		*starvation_check(void *arg);
void		eating_with_forks(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
void		print_message(t_setup *setting, int id, t_task action);

#endif
