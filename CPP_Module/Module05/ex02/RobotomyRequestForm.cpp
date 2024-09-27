/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:36:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:21:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45) {
	std::cout << "A Robotomy is created by default\n" << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), 72, 45) {
	std::cout << "A Robotomy is copied\n" << *this << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	(void)&other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "A Robotomy is destroyed" << std::endl;
}

void	RobotomyRequestForm::rollout() const {
	std::cout << "Zz................." << std::endl;
	usleep(500000);
	std::cout << "Zzzz..............." << std::endl;
	usleep(500000);
	std::cout << "Zzzzzzzzz.........." << std::endl;
	if (rand() % 2) {
		std::cout << getName() << " has been robotized successfully!" << std::endl;
	}
	else {
		std::cout << getName() << " failed to robotize!" << std::endl;
	}
}