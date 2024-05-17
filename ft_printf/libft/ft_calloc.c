/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:13:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/16 14:38:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (i < (nmemb * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*tab_1;
	char	*arr_1;
	int	*tab_2;
	char	*arr_2;

	tab_1 = (int *)ft_calloc(10, sizeof(int));
	arr_1 = (char *)ft_calloc(10, sizeof(char));
	tab_2 = (int *)calloc(10, sizeof(int));
	arr_2 = (char *)calloc(10, sizeof(char));
	printf("calloc test 1st elem: %d, add: %p\n", tab_1[0], tab_1);
	printf("calloc test 1st elem: %c, add: %p\n", arr_1[0], arr_1);
	printf("calloc real 1st elem: %d, add: %p\n", tab_2[0], tab_2);
	printf("calloc real 1st elem: %c, add: %p\n", arr_2[0], arr_2);
	free(tab_1);
	free(arr_1);
	free(tab_2);
	free(arr_2);
	return (0);
}*/
