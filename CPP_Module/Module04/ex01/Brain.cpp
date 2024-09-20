/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:11:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 17:55:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _i(0) {
	std::cout << "A Brain object is created" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "A Brain is copied from another Brain" << std::endl; 
	*this = other;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "A Brain object is destroyed" << std::endl;
}

std::string const	&Brain::getIdea(unsigned int i) const {
	return this->ideas[i];
}

void	Brain::setIdea(std::string const &str) {
	this->ideas[this->_i % 100] = str;
	this->_i++;
}