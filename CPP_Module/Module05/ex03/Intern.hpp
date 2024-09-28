/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:32:20 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/28 09:56:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	enum Types {
		SHRUB,
		ROBOT,
		PREPA,
		NONE
	};
private:
	/* data */
	Types	getFormTypes(std::string const &form);
public:
	Intern();
	Intern(Intern const &other);
	Intern&	operator=(Intern const &other);
	~Intern();
	
	AForm	*makeForm(std::string form, std::string target);
	/* exception class */
	class NonExistingFormException;
};

#endif