/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:42:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/24 17:31:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define ER STDERR_FILENO
# define AD_SIZE 16
# define HEX_SIZE 16
# define DEC_TAB "0123456789"
# define HEX_TAB "0123456789abcdef"
# define HEX_TAB_U "0123456789ABCDEF"

int		ft_print_spec(char c, va_list *ap);
int		ft_print_spec_left(char c, va_list *ap, int wid, int pre);
int		ft_print_spec_zero(char c, va_list *ap, int wid, int pre);
int		ft_print_spec_emty(char c, va_list *ap, int wid, int pre);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_mem(void *addr);
int		ft_print_digit(long nbr, char *base);
int		ft_printf(const char *fmt, ...);
int		ft_is_spec(char c);
char	*ft_procs_flag(const char *fmt, va_list *ap, int *count);
void	ft_gen_wid_pre(const char *fmt, size_t len, int *wid, int *pre);
int		ft_print_digit_left(long nbr, char *base, int wid, int pre);
int		ft_print_digit_zero(long nbr, char *base, int wid, int pre);
int		ft_print_digit_emty(long nbr, char *base, int wid, int pre);

#endif
