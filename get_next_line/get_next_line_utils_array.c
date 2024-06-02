/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:58:34 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/02 16:25:14 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_search_next_line(char **str_rd, int fd)
{
	char	*next_line;
	char	*tmp;
	int		nu_rd;
	char	buff[BUFFER_SIZE];
	char	*tmp_str;

	tmp = ft_strchr(*str_rd, '\n');
	nu_rd = 1;
	while (!tmp)
	{
		tmp_str = ft_strdup(*str_rd);
		free(*str_rd);
		nu_rd = read(fd, buff, BUFFER_SIZE);
		if (!nu_rd)
			break ;
		*str_rd = (char *)ft_calloc((ft_strlen(tmp_str) + nu_rd + 1), sizeof(char));
		if (!(*str_rd))
			return (NULL);
		ft_strlcat(*str_rd, tmp_str, ft_strlen(tmp_str) + 1);
		ft_strlcat(*str_rd, buff, nu_rd + 1);
		free(tmp_str);
		tmp = ft_strchr(*str_rd, '\n');
	}
	if (!tmp)
		return (NULL);
	next_line = ft_substr(*str_rd, 0, tmp - *str_rd + 1);
	tmp_str = (char *)ft_calloc((ft_strlen(*str_rd) - ft_strlen(next_line) + 1), sizeof(char));
	if (!tmp_str)
		return (NULL);
	ft_strlcat(tmp_str, tmp + 1, (ft_strlen(*str_rd) - ft_strlen(next_line) + 1));
	free(*str_rd);
	*str_rd = ft_strdup(tmp_str);
	free(tmp_str);
	return (next_line);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	n;
	int		i;

	i = 0;
	n = ft_strlen(s);
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
