/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:54:22 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/29 19:33:47 by tsuchen          ###   ########.fr       */
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
# define BUFFER_SIZE 512 
# define ER STDERR_FILENO

char	*get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
size_t  ft_strlcat(char *dst, const char *src, size_t siz);
size_t  ft_strlcpy(char *dst, const char *src, size_t siz);

#endif
