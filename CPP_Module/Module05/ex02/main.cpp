/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:53:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/27 12:51:44 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	AForm	*home = new ShrubberyCreationForm("home");
	RobotomyRequestForm	toilet("toilet");
	PresidentialPardonForm	donald("Donald");

	Bureaucrat	dave("Dave");
	dave.signForm(*home);
	dave.signForm(toilet);
	dave.signForm(donald);
	dave.executeForm(*home);
	dave.executeForm(toilet);
	dave.executeForm(donald);

	Bureaucrat	hugo("Hugo", 60);
	hugo.signForm(*home);
	hugo.signForm(toilet);
	hugo.signForm(donald);
	hugo.executeForm(*home);
	hugo.executeForm(toilet);
	hugo.executeForm(donald);

	Bureaucrat	zack("Zack", 5);
	zack.signForm(toilet);
	zack.signForm(donald);
	zack.executeForm(toilet);
	zack.executeForm(donald);
	
	delete home;
}