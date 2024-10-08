/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:57:41 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:09:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string	const _name;
	bool	_signed;
	int	const	_gradeToSign;
	int	const	_gradeToExec;
public:
	Form();
	Form(std::string const &name);
	Form(std::string const &name, int sign, int exec);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();
	/* accessors */
	std::string	const	&getName() const;
	bool	getSignedStatus() const;
	int		getGradeToSign() const;
	int		getGradeToExec() const;
	/* utils */
	void	beSigned(const Bureaucrat& agent);
	/* exception classes */
	class GradeTooHighException;
	class GradeTooLowException;
};

std::ostream & operator<<(std::ostream & o, Form const &rhs);

#endif