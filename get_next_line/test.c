/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:05:08 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/02 20:55:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_call_string(char *s)
{
	static int	cnt;
	static char	*str_rd;

	//str_rd = NULL;
	//cnt = 0;
	if (!str_rd)
		str_rd = strdup(s);
	else if (strcmp(s, str_rd))
	{
		free(str_rd);
		printf("str already existed!\n");
		str_rd = strdup(s);
	}
	printf("str is:%s; cnt is:%d\n", str_rd, cnt);
	cnt++;
	return ;
}

int	main(void)
{
	char	*s= "This is a string!";

	ft_call_string(s);
	ft_call_string(s);
	s = "I changed";
	ft_call_string(s);
	return (0);
}
