/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:17:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 11:33:21 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {
}

Point&	Point::operator=(const Point& other) {
	if (this != &other) {
		this->_x = other.getX();
		this->_y = other.getY();
	}
	return *this;
}

Point::~Point(void) {
}

Fixed	const &Point::getX(void) const {
	return this->_x;
}

Fixed	const &Point::getY(void) const {
	return this->_y;
}
