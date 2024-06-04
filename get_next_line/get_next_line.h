/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:54:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/04 21:20:17 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define ER STDERR_FILENO

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

void	ft_lst_append(t_list **lst, char *str);
void	ft_update_list(t_list **lst);
void	ft_delone(t_list *lst);
int		ft_have_nl_lst(t_list *bgn_lst);
int		ft_line_size(t_list *lst);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_gen_nl(t_list *lst);
void	ft_fetch_nl(int fd, t_list **bgn_lst);

#endif
