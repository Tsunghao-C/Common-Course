/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:47:39 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/26 22:27:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err1_argc(int ac)
{
	dup2(ERR, OUT);
	ft_printf("%s: Too few arguments: %d is given\n", P_NAME, ac - 1);
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
}

void	ft_err4_fork(int err_no)
{
	dup2(ERR, OUT);
	ft_printf("%s: %s\n", P_NAME, strerror(err_no));
	exit(4);
}

void	ft_err5_write(int err_no, char *file, char *line)
{
	free(line);
	dup2(ERR, OUT);
	ft_printf("%s: %s: %s\n", P_NAME, strerror(err_no), file);
	exit(5);
}
