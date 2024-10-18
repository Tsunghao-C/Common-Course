/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:20:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 12:09:52 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const &input) {
	if (!this->parse_input(input)) {
		throw std::runtime_error("invalid argument!!!");
	}
}

RPN::RPN(RPN const &other) { *this = other; }

RPN&    RPN::operator=(RPN const &other) {
	if (this != &other) {
		this->_input = other._input;
	}
	return *this;
}

RPN::~RPN() {}

bool    RPN::parse_input(std::string input) {
	std::string::iterator	start = std::find_if(input.begin(), input.end(), std::not1(std::ptr_fun<int, int>(isspace)));
	while (start != input.end()) {
		std::string::iterator	end = std::find_if(start, input.end(), std::ptr_fun<int, int>(isspace));
		std::string		element = std::string(start, end - 1);
		for (std::string::iterator it = element.begin(); it != element.end(); ++it) {
			if (!isdigit(*it) && !isoperator(*it)) {
				return false;
			}
		}
		_input.push(element);
		start = std::find_if(end, input.end(), std::not1(std::ptr_fun<int, int>(isspace)));
	}
	return true;	
}

bool	RPN::isoperator(int c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

double	RPN::do_rpn_cal() {
	
}