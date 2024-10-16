/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:29:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 17:21:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::OutOfRangeException : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("Out of container maximum capacity!");
	}
};

class Span::NoRangeException : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("No span possible!");
	}
};

Span::Span() : _n(100), _stored(0) {}

Span::Span(unsigned int n) : _n(n), _stored(0) {}

Span::Span(Span const &other) {*this = other;}

Span&	Span::operator=(Span const &other) {
	if (this != &other) {
		this->_n = other._n;
		this->_stored = other._stored;
		this->_cont = other._cont;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int number) {
	if (this->_stored >= this->_n)
		throw OutOfRangeException();
	std::vector<int>::iterator	it;
	for (it = this->_cont.begin(); it != this->_cont.end(); ++it) {
		if (number < *it) {
			break ;
		}
	}
	if (it == this->_cont.end()) {
		this->_cont.push_back(number);
	} else {
		this->_cont.insert(it, 1, number);
	}
	this->_stored += 1;
}

unsigned int	Span::shortestSpan() const {
	if (this->_stored < 2) {
		throw NoRangeException();
	}
	unsigned int	diff = *(this->_cont.begin() + 1) - *(this->_cont.begin());
	if (diff == 0)
		return diff;
	std::vector<int>::const_iterator	it;
	for (it = this->_cont.begin() + 1; it + 1 != this->_cont.end(); ++it) {
		unsigned int tmp = *(it + 1) - *it;
		if (tmp < diff) {
			diff = tmp;
		}
		if (diff == 0) {
			return diff;
		}
	}
	return diff;
}

unsigned int	Span::longestSpan() const {
	if (this->_stored < 2) {
		throw NoRangeException();
	}
	return (this->_cont.back() - this->_cont.front());
}

void	Span::fillNumbers(unsigned int n) {
	if (n > (this->_n - this->_stored)) {
		throw OutOfRangeException();
	}
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++) {
		const int value = rand();
		this->addNumber(value);
	}
}

void	Span::printAll() const {
	std::vector<int>::const_iterator it;
	for (it = this->_cont.begin(); it != this->_cont.end(); ++it) {
		std::cout << *it << std::endl;
	}
}