/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:57:41 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/08 19:12:20 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string	const _name;
	bool	_signed;
	int	const	_gradeToSign;
	int	const	_gradeToExec;
	std::string		_target;
public:
	AForm();
	AForm(std::string const &name);
	AForm(std::string const &name, int sign, int exec);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();
	/* accessors */
	std::string	const	&getName() const;
	bool	getSignedStatus() const;
	int		getGradeToSign() const;
	int		getGradeToExec() const;
	std::string const	&getTarget() const;
	void	setTarget(std::string const &target);
	/* utils */
	void	beSigned(Bureaucrat const & agent);
	void	execute(Bureaucrat const & executor) const;
	virtual void rollout() const = 0;	
	/* exception classes */
	class GradeTooHighException;
	class GradeTooLowException;
};

std::ostream & operator<<(std::ostream & o, AForm const &rhs);

#endif