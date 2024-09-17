/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:07:31 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/17 15:45:53 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int i) {
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i << this->_frac_bits);
}

Fixed::Fixed(const float f) {
	// std::cout << "Float constructor called" << std::endl;
	this->setRawBits(static_cast<int>(std::roundf(f * (1 << this->_frac_bits))));
}

Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

/* Arithmetic operator overloads */
Fixed	Fixed::operator+(const Fixed& rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed& rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed& rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed& rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

/* Comparison operator overloads */
int		Fixed::operator>(const Fixed& rhs) {
	if (this->toFloat() > rhs.toFloat())
		return true;
	return false;
}

int		Fixed::operator<(const Fixed& rhs) {
	if (this->toFloat() < rhs.toFloat())
		return true;
	return false;
}

int		Fixed::operator>=(const Fixed& rhs) {
	if (this->toFloat() >= rhs.toFloat())
		return true;
	return false;
}

int		Fixed::operator<=(const Fixed& rhs) {
	if (this->toFloat() <= rhs.toFloat())
		return true;
	return false;
}

int		Fixed::operator==(const Fixed& rhs) {
	if (this->toFloat() == rhs.toFloat())
		return true;
	return false;
}

int		Fixed::operator!=(const Fixed& rhs) {
	if (this->toFloat() != rhs.toFloat())
		return true;
	return false;
}

/* increment and decrement operator overloads */
Fixed&	Fixed::operator++(void) {
	this->_raw += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	this->_raw -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

/* min and max functions */
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	// std::cout << "max normal is alled" << std::endl;
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	// std::cout << "max const is alled" << std::endl;
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
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