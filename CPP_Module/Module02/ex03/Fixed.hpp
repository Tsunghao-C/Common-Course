/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:01:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/17 14:48:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed
{
private:
	/* data */
	int     _raw;
	static const int  _frac_bits;
	
public:
	Fixed(void);
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed(void);

	/* arithmetic operator overloads */
	Fixed	operator+(const Fixed& rhs);
	Fixed	operator-(const Fixed& rhs);
	Fixed	operator*(const Fixed& rhs);
	Fixed	operator/(const Fixed& rhs);

	/* comparison operator overloads */
	int		operator>(const Fixed& rhs);
	int		operator<(const Fixed& rhs);
	int		operator>=(const Fixed& rhs);
	int		operator<=(const Fixed& rhs);
	int		operator==(const Fixed& rhs);
	int		operator!=(const Fixed& rhs);

	/* increment and decrement overlaods */
	Fixed&	operator++(void);	//pre increment
	Fixed	operator++(int);	//post increment
	Fixed&	operator--(void);	//pre increment
	Fixed	operator--(int);	//post decrement

	/* min max functions */
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void)	const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif