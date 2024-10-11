/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:07:17 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 11:33:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _c('X'), _i(42), _f(94.87f), _s("default"), _addr(NULL) {
	std::cout << "Data created with default values" << std::endl;
	this->printData();
}

Data::Data(char c) : _c(c) {
	std::cout << "Data created with char" << std::endl;
	this->printData();
}

Data::Data(int i) : _i(i) {
	std::cout << "Data created with int" << std::endl;
	this->printData();
}

Data::Data(float f) : _f(f) {
	std::cout << "Data created with float" << std::endl;
	this->printData();
}

Data::Data(std::string const &str) : _s(str) {
	std::cout << "Data created with string" << std::endl;
	this->printData();
}

Data::Data(void *ptr) : _addr(ptr) {
	std::cout << "Data created with pointer" << std::endl;
	this->printData();
}

Data::Data(char c, int i, float f, std::string const &s, void *ptr) :
	_c(c), _i(i), _f(f), _s(s), _addr(ptr)
{   
	std::cout << "Data created with all new value" << std::endl;
	this->printData();
}

Data::Data(Data const &other) {
	*this = other;
}

Data& Data::operator=(Data const &other) {
	if (this != &other) {
		_c = other._c;
		_i = other._i;
		_f = other._f;
		_s = other._s;
		_addr = other._addr;
	}
	return *this;
}

Data::~Data() {}

void    Data::printData() {
	std::cout <<
		"char:  " << this->_c << std::endl <<
		"int:   " << this->_i << std::endl <<
		"float: " << this->_f << std::endl <<
		"str:   " << this->_s << std::endl <<
		"ptr:   " << this->_addr << std::endl;
}