/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:36:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:12:32 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too High!!!";
	}
};

class AForm::GradeTooLowException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too Low!!!";
	}
};

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(80), _gradeToExec(70), _target("") {
	std::cout << "A Form " << _name << " is created by default constructor" << std::endl;
}

AForm::AForm(std::string const &name) : _name(name), _signed(false), _gradeToSign(80), _gradeToExec(70), _target("") {
	std::cout << "A Form " << _name << " is created by default" << std::endl;
}

AForm::AForm(std::string const &name, int sign, int exec) : _name(name), _signed(false), _gradeToSign(sign), _gradeToExec(exec), _target("") {
	if (sign > 150 || exec > 150) {
		throw GradeTooLowException();
	}
	else if (sign < 1 || exec < 1) {
		throw GradeTooHighException();
	}
	std::cout << "A Form " << _name << " is created by specific grades" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	*this = other;
	std::cout << "A Form is copied" << std::endl;
}

AForm&   AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_signed = other._signed;
		this->_target = other._target;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "A Form is destroyed" << std::endl;
}

std::string const   &AForm::getName() const {
	return this->_name;
}

bool	AForm::getSignedStatus() const {
	return this->_signed;
}

int		AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int		AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

std::string const	&AForm::getTarget() const {
	return this->_target;
}

void	AForm::setTarget(std::string const &target) {
	this->_target = target;
}

void	AForm::beSigned(Bureaucrat const & agent) {
	if (this->getSignedStatus() == true) {
		throw std::runtime_error("it has been signed already!");
	}
	if (agent.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (this->getSignedStatus() == false) {
		throw std::runtime_error("Form not signed!");
	}
	if (executor.getGrade() > this->_gradeToExec) {
		throw GradeTooLowException();
	}
	this->rollout();
}

std::ostream & operator<<(std::ostream & o, AForm const &rhs) {
	o << "Form name: " << rhs.getName() << "\n"
		<< "\tTarget: " << rhs.getTarget() << "\n"
		<< "\tSigned status: " << rhs.getSignedStatus() << "\n"
		<< "\tGrade to Sign: " << rhs.getGradeToSign() << "\n"
		<< "\tGrade to Exec: " << rhs.getGradeToExec();
	return o;
}