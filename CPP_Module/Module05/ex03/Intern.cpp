/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:40:01 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/28 13:38:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

class Intern::NonExistingFormException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Not an existing form type!!!";
	}
};

Intern::Intern() {
	std::cout << "An Intern is created by default" << std::endl;
}

Intern::Intern(Intern const &other) {
	std::cout << "An Intern is copied" << std::endl;
	*this = other;
}

Intern&	Intern::operator=(Intern const &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "An Intern is destroyed" << std::endl;
}

Intern::Types	Intern::getFormTypes(std::string const &form) {
	const std::string form_types[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	for (int i = 0; i < 3; i++) {
		if (form_types[i] == form)
			return (Types)i;
	}
	return NONE;
}

AForm	*Intern::makeForm(std::string form, std::string target) {
	AForm	*newForm;
	for (std::string::iterator it = form.begin(); it < form.end(); ++it) {
		*it = std::tolower(*it);
	}
	try
	{
		/* code */
		switch (this->getFormTypes(form))
		{
		case SHRUB:
			newForm = new ShrubberyCreationForm(target);
			break;
		case ROBOT:
			newForm = new RobotomyRequestForm(target);
			break;
		case PREPA:
			newForm = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::NonExistingFormException();
			break;
	}
	std::cout << "Intern creates [" << newForm->getName() << "] with target [" << newForm->getTarget() << "]" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern failed to create [" << form << "] because " << e.what() << std::endl;
	}
	return newForm;
}