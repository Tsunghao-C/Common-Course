/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:44:31 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 16:51:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->setName("");
	std::cout << "A nameless Zombie class created." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << this->_name << " from Zombie class created." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " from Zombie class destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}