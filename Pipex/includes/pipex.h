/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/23 01:23:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# define OUT STDOUT_FILENO
# define IN STDIN_FILENO
# define ERR STDERR_FILENO
# define P_NAME "pipex"
# define BUFF 4096

/* unix utils */
void	ft_free_all(char **arr);
void	ft_init_pipe(int fd[][2], int n_pipes);
void	ft_close_others(int fd[][2], int rep, int n_pipes);
void	ft_read_n_write(char *file_in, int fd_pw);
void	ft_read_n_write2(char *file_out, int fd_pr);
void	ft_wait_all(int childs, int *pid);
int	ft_do_child(int fd[][2], int ac, char **av, int *pid);
int	ft_do_parent(int fd[][2], int ac, char **av);
/* error functions */
void	ft_err1_argc(int ac);
void	ft_err2_pipe(int err_no);
void	ft_err3_open(int err_no, char *file);
void	ft_err4_fork(int err_no);
void	ft_err5_read(int err_no, char *file);
void	ft_err6_malloc(int rep, int pid);

#endif
