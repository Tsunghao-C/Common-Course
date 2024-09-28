/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:18:28 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:34:44 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	/* data */
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat(std::string const &name);
	Bureaucrat(std::string const &name, int	grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();
	
	/* accessors */
	int		getGrade() const;
	std::string const	&getName() const;
	/* utils */
	void	increment();
	void	decrement();
	void	signForm(AForm& doc);
	void	executeForm(AForm const & form);
	/* execption classes*/
	class GradeTooHighException;
	class GradeTooLowException; 
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &rhs);

#endif