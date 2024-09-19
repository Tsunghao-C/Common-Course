/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:24:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 11:26:42 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	
	Point	a(3, -1);
	Point	b(-1, 5);
	Point	c(-4, -3);

	Point	p1;
	Point	p2(-3, -2);
	Point	p3(13, -2);
	Point	p4(b);

	std::cout << "p1 is: " << std::endl << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 is: " << std::endl << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 is: " << std::endl << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4 is: " << std::endl << bsp(a, b, c, p4) << std::endl;

	return 0;
}