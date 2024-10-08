/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:32:09 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:07:24 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too High!!!";
	}
};

class Bureaucrat::GradeTooLowException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Grade Too Low!!!";
	}
};

Bureaucrat::Bureaucrat() : _name("Default"), _grade(75) {
	std::cout << *this << " Created by default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(75) {
	std::cout << *this << " Created by default grade" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << *this << " Created with specific grade" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
	*this = other;
	std::cout << *this << " Created by copy" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << *this << " Destroyed" << std::endl;
}

std::string	const	&Bureaucrat::getName() const {
	return this->_name;
}

int		Bureaucrat::getGrade() const {
	return this->_grade;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}

void	Bureaucrat::increment() {
	if (getGrade() == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
	std::cout << _name << " incremented to " << _grade << std::endl;
}

void	Bureaucrat::decrement() {
	if (getGrade() == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
	std::cout << _name << " decremented to " << _grade << std::endl;
}

void	Bureaucrat::signForm(AForm& doc) {
	try
	{
		doc.beSigned(*this);
		std::cout << _name << " signed " << doc.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << doc.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute" << form.getName() << " because " << e.what() << std::endl;
	}
}