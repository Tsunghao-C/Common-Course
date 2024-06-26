/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:47:39 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/25 10:25:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err1_argc(int ac)
{
	dup2(ERR, OUT);
	ft_printf("Insufficient argument: %d is given\n", ac - 1);
	exit(1);
}

void	ft_err2_pipe(int err_no)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s\n", P_NAME, strerror(err_no));
	exit(2);
}

void	ft_err3_open(int err_no, char *file)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s: %s\n", P_NAME, strerror(err_no), file);
	exit(3);
}

void	ft_err4_fork(int err_no)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s\n", P_NAME, strerror(err_no));
	exit(4);
}

void	ft_err5_read(int err_no, char *file)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s: %s\n", P_NAME, strerror(err_no), file);
	exit(5);
}

void	ft_err6_malloc(int rep, int pid)
{
	dup2(ERR, OUT);
	ft_printf("%s: Child %d (PID:%d) malloc failed!\n", P_NAME, rep, pid);
	exit(6);
}

void	ft_err7_write(int err_no, char *file)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s: %s\n", P_NAME, strerror(err_no), file);
	exit(7);
}

void	ft_err8_unlink(int err_no)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s\n", P_NAME, strerror(err_no));
}

void	ft_err9_access(int err_no, char *path)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s\n", strerror(err_no), path);
}
