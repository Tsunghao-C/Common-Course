/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:25:40 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 12:30:59 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int     main() {
    Base    *random1 = generate();
    Base    *random2 = generate();
    Base    *random3 = generate();

    identify(random1);
    identify(random2);
    identify(random3);

    identify(*random1);
    identify(*random2);
    identify(*random3);

    delete random1;
    delete random2;
    delete random3;
    return 0;
}
