/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:18:26 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/17 17:53:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triArea(Point const a, Point const b, Point const c) {
	Fixed	area;
	
	area = ((a.getX() * (b.getY() - c.getY())) + 
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))) / Fixed(2);
	if (area < 0)
		return area * Fixed(-1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	A_abc = triArea(a, b, c);
	Fixed	A_pab = triArea(point, a, b);
	Fixed	A_pbc = triArea(point, b, c);
	Fixed	A_pca = triArea(point, c, a);
	
	// std::cout << "A_abc is: " << A_abc << std::endl;
	// std::cout << "A_pab is: " << A_pab << std::endl;
	// std::cout << "A_pbc is: " << A_pbc << std::endl;
	// std::cout << "A_pcs is: " << A_pca << std::endl;
	
	if (A_pab == 0 || A_pbc == 0 || A_pca == 0)
		return false;
	if ((A_pab + A_pbc + A_pca) <= A_abc)
		return true;
	return false;
}