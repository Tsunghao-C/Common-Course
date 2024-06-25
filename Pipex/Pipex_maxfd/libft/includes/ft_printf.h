/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:42:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/15 12:37:03 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define ER STDERR_FILENO
# define AD_SIZE 16
# define HEX_SIZE 16
# define DEC_TAB "0123456789"
# define HEX_TAB "0123456789abcdef"
# define HEX_TAB_U "0123456789ABCDEF"

int			ft_print_spec(char c, va_list *ap);
int			ft_print_spec_f(char c, va_list *ap, char *flags, char **wid_pre);
int			ft_print_char(char c);
int			ft_print_char_f(char c, char *flags, char **wid_pre);
int			ft_print_str(char *s);
int			ft_print_str_f(char *s, char *flags, char **wid_pre);
int			ft_print_mem(void *addr);
int			ft_print_mem_f(void *addr, char *flags, char **wid_pre);
int			ft_print_digit(long nbr, char *base);
int			ft_print_uint_f(long nbr, char *base, char *flags, char **wid_pre);
int			ft_print_sint_f(long nbr, char *base, char *flags, char **wid_pre);
int			ft_print_sign(long *nbr, char *flags);
int			ft_print_alt(char *base);
int			ft_printf(const char *fmt, ...);
int			ft_dgt_cnt_abs(long nbr, char *base);
int			ft_is_spec(char c);
int			ft_is_left(char *str);
int			ft_have_zero(char *str);
int			ft_have_alt(char *str);
int			ft_have_space(char *str);
int			ft_have_plus(char *str);
const char	*ft_procs_flag(const char *fmt, va_list *ap, int *count);
void		ft_gen_wid_pre(const char *fmt, size_t len, char **wid_pre);
void		ft_rm_plus_space(char *str);
void		ft_rm_alt(char *str);

#endif
