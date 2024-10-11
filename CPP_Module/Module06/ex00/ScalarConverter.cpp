/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:22:03 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 10:41:33 by tsuchen          ###   ########.fr       */
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
	/* nan */
	// if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
	if (s == "nan" || s == "nanf")
		return NONE;
	/* char */
	if (s.length() == 1 && !isdigit(*s.begin()))
		return CHAR;
	/* int */
	int		i = std::atoi(s.c_str());
	if (s == std::to_string(i))
		return INT;
	/* float */
	if ((s == "inff" || s == "+inff" || s == "-inff") || is_float(s))
		return FLOAT;
	/* double */
	if (s == "inf" || s == "+inf" || s == "-inf" || is_double(s))
		return DOUBLE;
	return OTHER;
}

void ScalarConverter::convert(std::string s) {
	/* first check literal type */
	switch (getLiteralType(s))
	{
	case NONE:
		do_nan();
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