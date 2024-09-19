/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:07:31 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 10:43:41 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _raw(i << this->_frac_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _raw(static_cast<int>(std::roundf(f * (1 << _frac_bits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_raw = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->_raw;
}

void	Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}

float	Fixed::toFloat(void) const {
	const float	reverseScalar = 1.0f / (1 << this->_frac_bits);
	return this->getRawBits() * reverseScalar;
}

int		Fixed::toInt(void) const {
	return this->getRawBits() >> this->_frac_bits;
}

const int	Fixed::_frac_bits = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}