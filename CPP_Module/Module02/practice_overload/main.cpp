/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:53:46 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 18:21:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

int	main() {
	
	Integer		x( 10 );
	Integer		y( 30 );
	Integer		z( 0  );
	int		a = 3;
	int		b = 4;
	int		c;

	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Value of y: " << y << std::endl;
	// y = Integer(32);
	y = z = x;
	std::cout << "Value of y: " << y << std::endl;
	
	std::cout << "Value of z: " << z << std::endl;
	z = x + x + y;
	std::cout << "Value of z: " << z << std::endl;
	
	c = a + b;	// + and = operators is only overloaded in the scope of class Integer
	std::cout << "Non class operation a + b: " << c << std::endl;
	return 0;
}