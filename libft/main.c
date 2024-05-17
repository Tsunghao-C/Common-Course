/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:28:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/17 11:00:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	output_content(void *content)
{
	int	*tmp;

	tmp = (int *)content;
	ft_putnbr_fd(*tmp, 1);
}

void	*minus_two(void *content)
{
	void	*tmp;

	tmp = malloc(sizeof(int));
	if (!tmp)
		return (0);
	*(int *)tmp = *(int *)content - 2;
	return (tmp);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	int	a = 5;
	int	b = 6;
	int	i = 0;
	t_list	*bgl;
	t_list	*map;

	bgl = ft_lstnew(minus_two(&a));
	printf("ad of bgl before lst add: %p\n", bgl);
	while (i < 10)
	{
		ft_lstadd_front(&bgl, ft_lstnew(minus_two(&b)));
		i++;
	}
	printf("ad of bgl after lst add : %p\n", bgl);
	printf("ad of last after lst add: %p\n", ft_lstlast(bgl));
	printf("size of list is: %i\n", ft_lstsize(bgl));
	ft_lstiter(bgl, &output_content);
	write(1, "  <= Original list\n", 19);
	map = ft_lstmap(bgl, &minus_two, &del_content);
	ft_lstiter(map, &output_content);
	write(1, "  <= Mapped list\n", 17);
	ft_lstclear(&bgl, &del_content);
	ft_lstclear(&map, &del_content);
	return (0);
}
