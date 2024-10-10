/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:22:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/10 12:37:30 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::Types ScalarConverter::getLiteralType(std::string const &s) {
	/* limits */
	// if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
	if (s == "nan" || s == "nanf")
		return LIMITS;
	/* int */
	try
	{
		int		i = std::atoi(s.c_str());
		if (s == std::to_string(i))
			return INT;
	}
	catch(const std::exception& e) {/* Error doing atoi */}
	/* float */
	try
	{
		float	f = std::atof(s.c_str());
		(void)f;
		if (*s.rbegin() == 'f' || *s.rbegin() == 'F')
			return FLOAT;
	}
	catch(const std::exception& e) {/* Error doing atof */}
	/* double */
	try
	{
		double	d = std::atof(s.c_str());
		(void)d;
		if (s.find('.') != std::string::npos)
			return DOUBLE;
	}
	catch(const std::exception& e) {/* Error doing atof */}
	/* char */
	if (s.length() == 1)
		return CHAR;
	return OTHER;
}

void ScalarConverter::convert(std::string s) {
	/* first check literal type */
	switch (getLiteralType(s))
	{
	case LIMITS:
		do_nan(s);
		break;
	case CHAR:
		do_char(s);
		break;
	case INT:
		do_int(s);
		break;
	case FLOAT:
		do_float(s);
		break;
	case DOUBLE:
		do_double(s);
		break;
	default:
		do_other(s);
		break;
	}
}