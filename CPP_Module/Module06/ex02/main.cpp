/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:25:40 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 12:38:48 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *  generate(void);
void    identify(Base * p);
void    identify(Base & p);

int     main() {
    Base    *random1 = generate();
    usleep(500);
    Base    *random2 = generate();
    usleep(500);
    Base    *random3 = generate();

    std::cout << "Check using pointer" << std::endl;
    identify(random1);
    identify(random2);
    identify(random3);

    std::cout << "\nCheck using reference" << std::endl;
    identify(*random1);
    identify(*random2);
    identify(*random3);

    delete random1;
    delete random2;
    delete random3;
    return 0;
}