/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:49:43 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 12:08:29 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	/* data */
	Fixed const	_x;
	Fixed const _y;
	
public:
	Point(void);							// default constructor
	Point(const float x, const float y);	// construct with inputs 
	Point(const Point& other);				// cpy constructor
	Point&	operator=(const Point& other);	// cpy assign operator
	~Point(void);
	Fixed	const &getX(void) const;
	Fixed	const &getY(void) const;

};

Fixed	triArea(Point const a, Point const b, Point const c);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif