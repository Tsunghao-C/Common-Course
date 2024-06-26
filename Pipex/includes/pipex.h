/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:35:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/26 23:13:08 by tsuchen          ###   ########.fr       */
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
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# define OUT STDOUT_FILENO
# define IN STDIN_FILENO
# define ERR STDERR_FILENO
# define P_NAME "pipex"

/* for av init and here_doc */
int		ft_init_fdio(int *fd_in, int *fd_out, int ac, char **av);
int		ft_init_here_doc(char *file, char *eof);
void	ft_free_all(char **arr);
void	ft_do_pipe(char *cmd, char **env);
void	ft_do_fork_main(char *cmd, char **env);
/* exec utils */
int		ft_exec(char *av, char **env);
int		ft_isabs_path(char *file);
char	*ft_get_path(char *file, char **env);
char	**ft_get_allpath(char **env);
char	**ft_parse_cmd(char *av);
/* error functions */
void	ft_err1_argc(int ac);
void	ft_err2_pipe(int err_no);
void	ft_err3_open(int err_no, char *file);
void	ft_err4_fork(int err_no);
void	ft_err5_write(int err_no, char *file, char *line);
void	ft_err6_cmd(char *path, int err_no);
#endif
