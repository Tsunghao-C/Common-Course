/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:34:42 by tsuchen           #+#    #+#             */
/*   Updated: 2024/08/13 01:32:26 by tsuchen          ###   ########.fr       */
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
    int i;

    i = 0;
    write(ER, "Failed to create checker thread\n", 33);
    while (i < setting->phils)
    {
        if (setting->philos[i])
            kill(setting->philos[i], SIGTERM);
        i++;
    }
    destroy_setting(setting);
    exit(EXIT_FAILURE);
}
