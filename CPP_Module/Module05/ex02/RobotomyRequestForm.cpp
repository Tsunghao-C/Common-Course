/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:36:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:18:00 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {
	std::cout << "A Robotomy is created by default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45) {
	this->setTarget(target);
	std::cout << "A Robotomy is created by default\n" << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), 72, 45) {
	this->setTarget(other.getTarget());
	std::cout << "A Robotomy is copied\n" << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "A Robotomy is destroyed" << std::endl;
}

void	RobotomyRequestForm::rollout() const {
	srand(static_cast<unsigned int>(time(0)));
	std::cout << "Zz................." << std::endl;
	usleep(500000);
	std::cout << "Zzzz..............." << std::endl;
	usleep(500000);
	std::cout << "Zzzzzzzzz.........." << std::endl;
	if (rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotized successfully!" << std::endl;
	}
	else {
		std::cout << getTarget() << " failed to robotize!" << std::endl;
	}
}