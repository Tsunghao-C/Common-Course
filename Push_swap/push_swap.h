/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:15:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/17 12:17:35 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# define P_NAME "./push_swap"

void	ft_arg_check(char **av);
void	ft_del(void *content);
void	ft_init_stk(t_list **stk_a, char **av, void (*del)(void *));
/* Operations */
void	ft_sa(t_list **stk_a);
void	ft_sb(t_list **stk_b);
void	ft_ss(t_list **stk_a, **stk_b);
void	ft_pa(t_list **stk_b, t_list **stk_a);
void	ft_pb(t_list **stk_a, t_list **stk_b);
void	ft_ra(t_list **stk_a);
void	ft_rb(t_list **stk_b);
void	ft_rr(t_list **stk_a, t_list **stk_b);
void	ft_rra(t_list **stk_a);
void	ft_rrb(t_list **stk_b);
void	ft_rrr(t_list **stk_a, t_list **stk_b);
/* Sorting Methods */
int	ft_cmp(t_list *lst);
void	ft_2nodes_sort(t_list **stk_a);
void	ft_3nodes_sort(t_list **stk_a);

#endif
