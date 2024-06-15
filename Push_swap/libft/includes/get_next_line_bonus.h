/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:54:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 13:59:19 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024
# define ER STDERR_FILENO

typedef struct s_list_gnl
{
	char				*str;
	struct s_list_gnl	*next;
}	t_list_gnl;	
void	ft_lst_append(t_list_gnl **lst, char *str);
void	ft_update_list(t_list_gnl **lst);
void	ft_delone(t_list_gnl *lst);
int		ft_have_nl_lst(t_list_gnl *bgn_lst);
int		ft_line_size(t_list_gnl *lst);
char	*get_next_line(int fd);
char	*ft_gen_nl(t_list_gnl *lst);
void	ft_fetch_nl(int fd, t_list_gnl **bgn_lst);

#endif
