/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:12:32 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 11:30:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/* Note
 * 1. if s is NULL, it will crash at ft_strlen
 * 2. if s is not NULL but fd is -1, write will return -1 and set errno to EBADF
 */
/*
int	main(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	ft_putstr_fd(av[1], 1);
	return (0);
}*/
