/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:02:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/21 17:38:59 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

/* 4. demo of using a pipe part 2: parallel computing */
/*int	main(int ac, char *av[])
{
	int	arr[] = { 7, 6, 9, 1, 2, 4, 5, 3, 1, 4 };
	int	arr_size;
	int	id;
	int	id2;
	int	fd[2];
	int	start;
	int	end;
	int	sum;

	arr_size = sizeof(arr) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	// define job scope for each process
	if (id == 0)
	{
		id2 = fork();
		if (id2 == 0)
		{
			start = 0;
			end = arr_size / 3;
		}
		else
		{
			start = arr_size / 3;
			end = 2 * (arr_size / 3);
		}

	}
	else
	{
		start = 2 * (arr_size / 3);
		end = arr_size;
	}
	// do the job in each process
	sum = 0;
	while (start < end)
		sum += arr[start++];
	// deliver result through pipe
	if (id == 0)
	{
		if (id2 == 0)
		{
			close(fd[0]);
			if (write(fd[1], &sum, sizeof(int)) == -1)
				return (3);
			printf("sum from child_2 is %d\n", sum);
			close(fd[1]);
		}
		else
		{
			printf("sum from child_1 is %d\n", sum);
			wait(NULL);
			if (read(fd[0], &start, sizeof(int)) == -1)
				return (4);
			sum += start;
			close(fd[0]);
			if (write(fd[1], &sum, sizeof(int)) == -1)
				return (5);
			close(fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		printf("sum from parent is %d\n", sum);
		wait(NULL);
		if (read(fd[0], &start, sizeof(int)) == -1)
			return (6);
		sum += start;
		printf("total sum is %d\n", sum);
		close(fd[0]);
	}
	return (0);
}
// This exercise is trying to delagate a task into three parallel processes.
// One tricky part is where to put the wait function matters!
// Even the delegation is 3, the fd array for pipe is still 2:
// 	fd[0] for reading
// 	fd[1] for writing
*/

/* 3. demo of using a pipe */
/*int	main(int ac, char *av[])
{
	int	fd[2];
	int	id;
	int	x;
	int	y;

	if (pipe(fd) == -1)
	{
		perror(strerror(errno));
		return (1);
	}
	id = fork();
	if (id == -1)
	{
		perror(strerror(errno));
		return (2);
	}
	if (id == 0)
	{
		close(fd[0]);
		printf("input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			perror(strerror(errno));
			return (3);
		}
		close(fd[1]);
		printf("ID is :%d, PID is:%d\n", id, getpid());
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			perror(strerror(errno));
			return (4);
		}
		printf("Data read from child is :%d\n", y);
		printf("ID is :%d, PID is:%d\n", id, getpid());
		close(fd[0]);
	}
	return (0);
}
// You can use pipe to create a channel that allow processes to communicate to 
// each other.
*/

/* 2. demo for multiple forks */
/*int	main(int ac, char *av[])
{
	int	f_id1;
	int	f_id2;
	int	f_id3;

	f_id1 = fork();
	wait(NULL);
	f_id2 = fork();
	wait(NULL);
	f_id3 = fork();
	//if (f_id3 == 0)
	//	sleep(1);
	printf("F_id1 %5d | F_id2 %5d | F_id3 %5d | P_id %5d | PP_id %5d\n",
		f_id1, f_id2, f_id3, getpid(), getppid());
	//while (wait(NULL) != -1 || errno != ECHILD)
	//	printf("non-finished child existed!\n");
	wait(NULL);
	return (0);
}

// You need to put a "wait" whenever you craete a for if you want to make sure child always terminate before it parent does.
// See how the printf sequence change if you put wait before or after.
*/

/* 1. demo for fork and wait */
/*int	main(int ac, char *av[])
{
	int	id;

	id = fork();
	//if (id == 0)
	//	sleep(2);
	printf("Current id=%d, pid=%d, parent pid=%d\n",
		id, getpid(), getppid());
	printf("process:%d wait for process:%d\n", getpid(), wait(NULL));
	//if (wait(NULL) == -1)
	//	printf("No children to wait for\n");
	return (0);
}*/
