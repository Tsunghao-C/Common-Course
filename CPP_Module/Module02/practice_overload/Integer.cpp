/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:04 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 18:04:47 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

Integer::Integer(int const n) : _n(n) {
	std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer(void) {
    std::cout << "Destructor called with value " << this->_n << std::endl;
}

int Integer::getValue( void ) const {
    return this->_n;
}

Integer&    Integer::operator=( Integer const & rhs) {
    std::cout << "Assignment operator called from " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;

    this->_n = rhs.getValue();
    return *this;
}

Integer     Integer::operator+( Integer const & rhs) const {
    std::cout << "Addition operator called from " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;
    
    return Integer(this->_n + rhs.getValue());
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs) {
    o << rhs.getValue();
    return o;
}