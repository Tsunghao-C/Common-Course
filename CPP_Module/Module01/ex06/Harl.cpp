/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:57:23 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 11:46:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {	
}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl; 
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::others(void) {
	std::cout << "[Probably complaning about insigificant problems]" << std::endl;
}

t_cmpl	Harl::getComplaintype(std::string level) {
	const std::string	levels[5] = { "NONE", "DEBUG", "INFO", "WARNING", "ERROR" };
	
	for (int i = 0; i < 5; i++) {
		if (levels[i] == level)
			return (t_cmpl)i;
	}
	return NONE;
}

void	Harl::complain(std::string level) {
	void	(Harl::*ptr[5])(void) = { &Harl::others, &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	switch (this->getComplaintype(level))
	{
	case DEBUG:
		(this->*ptr[DEBUG])();
		std::cout << std::endl;
		// break;
	case INFO:
		(this->*ptr[INFO])();
		std::cout << std::endl;
		// break;
	case WARNING:
		(this->*ptr[WARNING])();
		std::cout << std::endl;
		// break;
	case ERROR:
		(this->*ptr[ERROR])();
		std::cout << std::endl;
		break;
	default:
		(this->*ptr[NONE])();
		break;
	}	
}
