/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:07:31 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/17 13:28:01 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i * (1 << this->_frac_bits));
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(std::round(f * (1 << this->_frac_bits))));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = other.getRawBits();
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
	const float	reverseScalar = 1.0f / (1 << this->_frac_bits);
	return this->getRawBits() * reverseScalar;
}

const int	Fixed::_frac_bits = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}