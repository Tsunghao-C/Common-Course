/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:34:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/20 01:43:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line_bonus.h"
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>
# define P_NAME "./checker"

/* Error Check and init Stack */
int		ft_peek(t_list *lst);
void	ft_arg_check(char **av);
void	ft_del(void *content);
void	ft_init_stk(t_list **stk_a, char **av, void (*del)(void *));
/* Operations */
void	ft_sa(t_list **stk_a, t_list **stk_b);
void	ft_sb(t_list **stk_a, t_list **stk_b);
void	ft_ss(t_list **stk_a, t_list **stk_b);
void	ft_pa(t_list **stk_a, t_list **stk_b);
void	ft_pb(t_list **stk_a, t_list **stk_b);
void	ft_ra(t_list **stk_a, t_list **stk_b);
void	ft_rb(t_list **stk_a, t_list **stk_b);
void	ft_rr(t_list **stk_a, t_list **stk_b);
void	ft_rra(t_list **stk_a, t_list **stk_b);
void	ft_rrb(t_list **stk_a, t_list **stk_b);
void	ft_rrr(t_list **stk_a, t_list **stk_b);
/* Do Operations */
int		ft_read_n_sort(t_list **stk_a, t_list **stk_b);
void	*ft_check_op(char *str);
void	ft_do_op(t_list **a, t_list **b, void (*f)(t_list **, t_list **));
#endif
