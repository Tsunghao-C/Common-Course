/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:34:42 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/12 20:59:26 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void    err_exit_fork(t_setup *setting)
{
    free(setting->philos);
    destroy_setting(setting);
    exit(EXIT_FAILURE);
}

void    err_exit_detach(void)
{
    write(ER, "Failed to detach a thread\n", 27);
    exit(EXIT_FAILURE);
}

void    err_exit_main(t_setup *setting)
{
    write(ER, "Failed to create checker thread\n", 33);
    kill(-1, SIGTERM);
    destroy_setting(setting);
    exit(EXIT_FAILURE);
}
