/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/25 12:29:37 by tsuchen          ###   ########.fr       */
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
int		ft_arrlen(char **arr);
void	ft_free_all(char **arr);
void	ft_init_pipe(int fd[][2], int n_pipes);
void	ft_close_others(int fd[][2], int rep, int n_pipes);
void	ft_read_n_write(char *file_in, int fd_pw);
void	ft_read_n_write2(char *file_out, int fd_pr, int mode);
void	ft_wait_all(int childs, int *pid);
int		ft_do_child(int fd[][2], int *pid, char **av, char **env);
int		ft_do_parent(int fd[][2], int ac, char **av);
int		ft_exec(char *av, char **env);
char	*ft_get_path(char *file, char **env);
char	**ft_get_allpath(char **env);
/* error functions */
void	ft_err1_argc(int ac);
void	ft_err2_pipe(int err_no);
void	ft_err3_open(int err_no, char *file);
void	ft_err4_fork(int err_no);
void	ft_err5_read(int err_no, char *file);
void	ft_err6_malloc(int rep, int pid);
void	ft_err7_write(int err_no, char *file);
void	ft_err8_unlink(int err_no);
void	ft_err9_access(int err_no, char *path);
/* for here_doc */
char	**ft_av_check(int ac, char **av);
int		ft_init_here_doc(char *file, char *eof);
int		ft_init_argv(char **argv, int ac, char **av);
#endif
