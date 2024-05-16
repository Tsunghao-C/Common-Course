/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_n_dsp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:29:29 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 17:55:10 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_read_n_dsp(int fd)
{
	int		rd;
	char	buff[BUFF_SIZE];

	buff[0] = '\0';
	rd = read(fd, buff, sizeof(buff));
	if (rd == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return ;
	}
	while (rd > 0)
	{
		write(1, buff, rd);
		rd = read(fd, buff, sizeof(buff));
	}
}
