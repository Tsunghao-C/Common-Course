/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:36:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/26 18:07:50 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Form::GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too High!!!";
	}
};

class Form::GradeTooLowException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too Low!!!";
	}
};

Form::Form(std::string const &name) : _name(name), _signed(false), _gradeToSign(80), _gradeToExec(70) {
	std::cout << "A Form " << _name << " is created by defualt" << std::endl;
}

Form::Form(std::string const &name, int sign, int exec) : _name(name), _signed(false), _gradeToSign(sign), _gradeToExec(exec) {
	if (sign > 150 || exec > 150) {
		throw GradeTooLowException();
	}
	else if (sign < 1 || exec < 1) {
		throw GradeTooHighException();
	}
	std::cout << "A Form " << _name << " is created by specific grades" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	*this = other;
	std::cout << "A Form is copied" << std::endl;
}

Form&   Form::operator=(const Form& other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "A Form is destroyed" << std::endl;
}

std::string const   &Form::getName() const {
	return this->_name;
}

bool	Form::getSignedStatus() const {
	return this->_signed;
}

int		Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int		Form::getGradeToExec() const {
	return this->_gradeToExec;
}

void	Form::beSigned(const Bureaucrat& agent) {
	if (agent.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream & operator<<(std::ostream & o, Form const &rhs) {
	o << "Form name: " << rhs.getName() << "\n"
		<< "\tSigned status: " << rhs.getSignedStatus() << "\n"
		<< "\tGrade to Sign: " << rhs.getGradeToSign() << "\n"
		<< "\tGrade to Exec: " << rhs.getGradeToExec();
	return o;
}