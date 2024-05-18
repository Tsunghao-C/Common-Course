/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:42:50 by tsuchen           #+#    #+#             */
/*   Updated: 2024/05/18 12:34:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# define ER STDERR_FILENO
# define AD_SIZE 12
# define HEX_SIZE 16
# define HEX_TAB "0123456789abcdef"

char	*ft_print_char(char *fmt);
char	*ft_print_spec(char *fmt, void **args, va_list *ap);
void	ft_putmem_fd(void *addr, int fd);

#endif
