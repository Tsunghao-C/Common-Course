/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:00:21 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/03 18:28:12 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isfractol(char *str)
{
	if (!strcmp(str, F1))
		return (1);
	else if (!strcmp(str, F2))
		return (2);
	else if (!strcmp(str, F3))
		return (3);
	else
		return (0);
}

void	ft_err1_args(void)
{
	ft_printf("%s: Invalid Input! Choose one of the following:\n", P_NAME);
	ft_printf("\t- %s\n\t- %s\n\t- %s\n", F1, F2, F3);
	exit(1);
}

void	ft_err2_mlx(char *model)
{
	ft_printf("%s: %s: Failed to init mlx\n", P_NAME, model);
	exit(2);
}
