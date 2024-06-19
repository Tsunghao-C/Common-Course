/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:15:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/19 19:28:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# define P_NAME "./push_swap"

void	ft_arg_check(char **av);
void	ft_del(void *content);
void	ft_init_stk(t_list **stk_a, char **av, void (*del)(void *));
void	ft_print_all(t_list *lst);
/* Operations */
void	ft_sa(t_list **stk_a);
void	ft_sb(t_list **stk_b);
void	ft_ss(t_list **stk_a, t_list **stk_b);
void	ft_pa(t_list **stk_b, t_list **stk_a);
void	ft_pb(t_list **stk_a, t_list **stk_b);
void	ft_ra(t_list **stk_a, int rep);
void	ft_rb(t_list **stk_b, int rep);
void	ft_rr(t_list **stk_a, t_list **stk_b, int rep);
void	ft_combo_rr_rx(t_list **from, t_list **to, int rep_1, int rep_2);
void	ft_rra(t_list **stk_a, int rep);
void	ft_rrb(t_list **stk_b, int rep);
void	ft_rrr(t_list **stk_a, t_list **stk_b, int rep);
void	ft_combo_rrr_rrx(t_list **from, t_list **to, int rep_1, int rep_2);
/* Sorting Methods */
int		ft_cmp(t_list *lst);
void	ft_3nodes_sort(t_list **stk_a);
void	ft_tiny_sort(t_list **stk_a, t_list **stk_b, int nodes);
void	ft_sort_list(t_list **stk_a, t_list **stk_b, int size);
/* sort utils */
int		ft_bigger(int a, int b);
int		ft_smaller(int a, int b);
int		ft_peek(t_list *lst);
int		ft_max(t_list *lst);
int		ft_min(t_list *lst);
int		ft_get_loc(t_list *lst, int target);
int		ft_target_ba(t_list *lst, int ref);
int		ft_target_ab(t_list *lst, int ref);
int		ft_is_rotate(t_list *lst, int target);
void	ft_push_checkb2a(t_list **from, t_list **to);
void	ft_sort_stk_a(t_list **stk_a);
/* Cheapest utils */
int		ft_cal_steps_ab(t_list *from, int loc, int size, t_list *to);
int		ft_cal_steps_ba(t_list *from, int loc, int size, t_list *to);
int		ft_find_cheapest_ab(t_list *from, int size, t_list *to);
int		ft_find_cheapest_ba(t_list *from, int size, t_list *to);
void	ft_cheap_checka2b(t_list **from, int size, t_list **to, int to_size);
void	ft_cheap_checkb2a(t_list **from, int size, t_list **to, int to_size);

#endif
