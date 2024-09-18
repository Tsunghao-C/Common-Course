/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:03:38 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 09:29:36 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string a_type) : _type(a_type) {
	std::cout << "A weapon object created" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "A weapon object destroyed" << std::endl;
}

std::string	Weapon::getType(void) const {
	return this->_type;
}

void	Weapon::setType(std::string a_type) {
	std::cout << "Weapon type changed from [" << this->_type << "] to [" << a_type << "]" << std::endl;
	this->_type = a_type;
}