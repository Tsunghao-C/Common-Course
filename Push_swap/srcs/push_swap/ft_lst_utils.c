/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:35:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 11:20:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(void *content)
{
	free(content);
}

void	ft_init_stk(t_list **stk_a, int ac, char **av, void (*del)(void *))
{
	t_list	*tmp_list;
	char	*tmp_str;
	int		i;

	i = 0;
	if (ac != 2)
		i++;
	while (av[i])
	{
		tmp_str = ft_strdup(av[i]);
		tmp_list = ft_lstnew(tmp_str);
		if (!tmp_list)
		{
			del(tmp_str);
			ft_lstclear(stk_a, del);
			return ;
		}
		ft_lstadd_back(stk_a, tmp_list);
		i++;
	}
	return ;
}

void	ft_print_all(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("lst :%p | val :%d | prev :%14p | next :%14p\n", tmp,
			ft_peek(tmp), tmp->prev, tmp->next);
		tmp = tmp->next;
	}
}
