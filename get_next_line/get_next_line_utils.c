/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:58:34 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/30 21:39:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (siz > 0)
	{
		while ((i < (siz - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}*/

void	ft_read_n_copy(static char **str_rd, int fd)
{
	int		nu_rd;
	int		i;
	char		buff[BUFFER_SIZE];
	char		*tmp;

	nu_rd = read(fd, buff, BUFFER_SIZE);
	if (nu_rd == -1)
		return ;
	i = 0;
	tmp = NULL;
	while (!ft_strchr(buff, '\n'))
	{
		i += nu_rd;
		if (*str_rd)
		{
			tmp = ft_strdup(*str_rd);
			free (*str_rd);
		}
		*str_rd = (char *)malloc((i + 1) * sizeof(char));
		if (!str_rd)
			return ;
		**str_rd = 0;
		if (tmp)
		{
			ft_strlcat(*str_rd, tmp, ft_strlen(tmp) + 1);
			free (tmp);
		}
		ft_strlcat(*str_rd, buff, (i + 1));
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (nu_rd == -1)
			return ;
	}
	i += nu_rd;
	if (*str_rd)
	{
		tmp = ft_strdup(*str_rd);
		free(*str_rd);
	}
	*str
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (siz < dst_len + 1)
		return (src_len + siz);
	i = 0;
	while (src[i] && i < (siz - dst_len - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;

	i = 0;
	if (start > ft_strlen(s))
		size = 0;
	else
	{
		size = ft_strlen(s) - start;
		if (ft_strlen(s) - start > len)
			size = len;
	}
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (i < size && s[i + start])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			return ((char *)tmp);
		tmp++;
	}
	if (*tmp == (unsigned char)c)
		return ((char *)tmp);
	return (NULL);
}
