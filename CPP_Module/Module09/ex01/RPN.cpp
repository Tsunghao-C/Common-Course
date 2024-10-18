/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:20:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/18 13:40:31 by tsuchen          ###   ########.fr       */
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
		std::string		element = std::string(start, end);
		for (std::string::iterator it = element.begin(); it != element.end(); ++it) {
			if (!isdigit(*it) && !isoperator(*it)) {
				return false;
			}
		}
		// std::cout << element << " ";
		_input.push(element);
		start = std::find_if(end, input.end(), std::not1(std::ptr_fun<int, int>(isspace)));
	}
	// std::cout << std::endl;
	return true;	
}

bool	RPN::isoperator(int c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	return false;
}

double	RPN::do_operator(std::string const &op, double left, double right) {
	if (op == "+") {
		return (left + right);
	} else if (op == "-") {
		return (left - right);
	} else if (op == "*") {
		return (left * right);
	} else {
		return (left / right);
	}
}

double	RPN::do_rpn_cal() {
	if (_input.empty()) {
		throw std::runtime_error("cannot complete calculation!!");
	}
	std::string	top_elem = _input.top();
	_input.pop();
	if (top_elem.length() == 1 && isoperator(*top_elem.begin())) {
		double	right_operand = do_rpn_cal();
		// std::cout << "rigt: " << right_operand << std::endl;
		double	left_operand = do_rpn_cal();
		// std::cout << "left: " << left_operand << std::endl;
		// std::cout << "left: " << left_operand << " " << top_elem << " rigt: " << right_operand << " = ";
		// std::cout << do_operator(top_elem, left_operand, right_operand) << std::endl;
		return do_operator(top_elem, left_operand, right_operand);
	}
	return std::atof(top_elem.c_str());
}