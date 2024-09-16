/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:35:08 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 11:55:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name) {
    this->_weapon_b = nullptr;
    std::cout << "HumanB " << this->_name << " is created" << std::endl;
}

HumanB::~HumanB(void) {
    std::cout << "HumanB " << this->_name << " is destroyed" << std::endl;
}

void    HumanB::attack(void) {
    if (!this->_weapon_b)
        std::cout << this->_name << " attacts with bare hands" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon_b->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &w) {
    this->_weapon_b = &w;
    std::cout << this->_name << " equiped with weapon " << this->_weapon_b->getType() << std::endl;
}
