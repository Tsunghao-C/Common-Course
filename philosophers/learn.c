/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:23:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/05 15:21:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/* Passing args to and getting args from threads */

int	prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void	*routine(void *arg)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 5)
	{
		sum += prime[*(int *)arg + i];
		i ++;
	}
	printf("Local Sum is: %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(int ac, char *av[])
{
	pthread_t	th[2];
	int		i;
	int		*a;
	int		*res;
	int		final_sum;

	i = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, &routine, a))
			perror("Failed to create thread");
		i++;
	}
	i = 0;
	final_sum = 0;
	while (i < 2)
	{
		//res = malloc(sizeof(int));
		if (pthread_join(th[i], (void **)&res))
			perror("Failed to join thread");
		final_sum += *res;
		free(res);
		i++;
	}
	printf("Global SUM is: %d\n", final_sum);
	return (0);
	// IMPORTANT: return the same pointer in the ROUTINE function to keep
	// track of the status and free until it is joined. It is malloced in
	// the loop of thread creation and freed in the loop of thread joint.
}

/* Passing arguments to threads*/
/*
int	prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void	*routine(void *arg)
{
	printf("%d ", prime[*(int *)arg]);
	//free(arg);
	return (NULL);
}

int	main(int ac, char *av[])
{
	pthread_t	th[10];
	int		index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int		i;
	//int		*a;

	i = 0;
	while (i < 10)
	{
		//a = malloc(sizeof(int));
		//\*a = i;
		if (pthread_create(&th[i], NULL, &routine, index + i))
			perror("Failed to create thread");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL))
			perror("Failed to join thread");
		i++;
	}
	return (0);
	// IMPORTANT: Be carefull about the pointer that is going to sent
	// to the threads. Make sure it WILL NOT CHANGE over time!!!
}*/

/* Mutex and how to return value from a thread */
/*
void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result;

	result = malloc(sizeof(int));
	*result = value;
	printf("result from roll_dice: %d\n", *result);
	return (result);
	// thre return value needs to be a pointer in heap
}

int	init_threads(pthread_t *th, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_create(&th[i], NULL, &roll_dice, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	join_threads(pthread_t *th, int num, void ** res, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_lock(mutex);
		if (*res)
			free(*res);
		if (pthread_join(th[i], res))
			return (2);
		printf("Result from thread %d is: %d\n", i, **(int **)res);
		i++;
		pthread_mutex_unlock(mutex);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	int	*res;
	pthread_t	th[4];
	pthread_mutex_t	mutex;

	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	res = NULL;
	//if (pthread_create(&th, NULL, &roll_dice, NULL))
	if (init_threads(th, 4))
		return (1);
	//if (pthread_join(th, (void **)&res))
	if (join_threads(th, 4, (void **)&res, &mutex))
		return (2);
	free(res);
	pthread_mutex_destroy(&mutex);
	return (0);
}*/

/* Mutex and how to create multiple thread in a loop*/
/*
int	mails = 0;
//int	lock = 0;
pthread_mutex_t	mutex;	//the lock of mutex;

void	*routine()
{
	int	i;

	i = 0;
	while (i++ < 1000000)
	{
		//if (lock == 1)
		//{
		//	// wait until the lock is 0
		//}
		//lock = 1; // lock it and start to process
		pthread_mutex_lock(&mutex);
		mails++; // processing
		//lock = 0; // unlock when finish processing
		pthread_mutex_unlock(&mutex);
		// read mails
		// increment
		// write mails
	}
	return (NULL);
}*/
/*
int	main(int ac, char *av[])
{
	//pthread_t	t1;
	//pthread_t	t2;
	//pthread_t	t3;
	pthread_t	th[3];
	int		i;
	pthread_mutex_init(&mutex, NULL);

	//if (pthread_create(&t1, NULL, &routine, NULL))
	//	return (1);
	//if (pthread_create(&t2, NULL, &routine, NULL))
	//	return (2);
	//if (pthread_create(&t3, NULL, &routine, NULL))
	//	return (2);
	i = 0;
	while (i < 3)
	{
		if (pthread_create(&th[i++], NULL, &routine, NULL))
		{
			perror("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n", i);
	}
	//if (pthread_join(t1, NULL))
	//	return (3);
	//if (pthread_join(t2, NULL))
	//	return (4);
	//if (pthread_join(t3, NULL))
	//	return (4);
	i = 0;
	while (i < 3)
	{
		if (pthread_join(th[i++], NULL))
			return (2);
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Total mails is %d\n", mails);
	return (0);
	// IMPORTANT: DO NOT create and join thread in a same iteration
	// loop, this case it will not do parallel tasks
}*/

/* Race conditions */
/*
int	mails = 0;

void	*routine()
{
	int	i;

	i = 0;
	while (i++ < 10000)
	{
		mails++;
		// read mails
		// increment
		// write mails
	}
	return (NULL);
	// To solve race conditions in thread, we use 
	// mutual exclusive lock (MUTEX)
}
*/

/* intro to thread */
/*
int	x = 2;

void	*routine()
{
	//printf("Test from threads\n");
	//sleep(2);
	//printf("End of test\n");
	x += 4;
	sleep(1);
	printf("Value of thread 1 x = %d\n", x);
	return (NULL);
}

void	*routine2()
{
	//printf("Test from threads\n");
	//sleep(2);
	//printf("End of test\n");
	sleep(2);
	x += 4;
	printf("Value of thread 2 x = %d\n", x);
	return (NULL);
	// Even though threads share the memory of a global variable,
	// when to retrive the global variable is critical.
}
*/
/*
int	main(int ac, char *av[])
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);
	printf("Total mails is %d\n", mails);
	return (0);
}*/
