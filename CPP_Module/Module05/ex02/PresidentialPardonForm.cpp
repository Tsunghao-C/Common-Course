/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:06:48 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:20:24 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5) {
	std::cout << "A Presidential Pardon is created by default\n" << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), 25, 5) {
	std::cout << "A Presidential Pardon is copied\n" << *this << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	(void)&other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "A Presidential Pardon is destroyed" << std::endl;
}

void	PresidentialPardonForm::rollout() const {
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}