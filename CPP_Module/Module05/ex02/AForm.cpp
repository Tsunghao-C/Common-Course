/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:36:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:37:10 by tsuchen          ###   ########.fr       */
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

AForm::AForm(std::string const &name) : _name(name), _signed(false), _gradeToSign(80), _gradeToExec(70) {
	std::cout << "A Form " << _name << " is created by defualt" << std::endl;
}

AForm::AForm(std::string const &name, int sign, int exec) : _name(name), _signed(false), _gradeToSign(sign), _gradeToExec(exec) {
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
		<< "\tSigned status: " << rhs.getSignedStatus() << "\n"
		<< "\tGrade to Sign: " << rhs.getGradeToSign() << "\n"
		<< "\tGrade to Exec: " << rhs.getGradeToExec();
	return o;
}