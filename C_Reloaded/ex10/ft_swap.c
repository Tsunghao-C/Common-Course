/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:41:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/14 11:46:57 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
#include <stdio.h>
int	main(void)
{
	int	a = 42;
	int	b = 21;

	printf("before swap | a is %d; bis %d\n", a, b);
	ft_swap(&a, &b);
	printf("after swap  | a is %d; bis %d\n", a, b);
	return (0);
}*/
