/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:17:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 01:20:49 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::do_nan(std::string const &s) {
	std::cout << "--------DO NAN-----------" << std::endl;
	(void)s;
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << "nan" << "f" << std::endl;
	std::cout << "Double: " << "nan" << std::endl;
}

void ScalarConverter::do_char(std::string const &s) {
	std::cout << "--------DO CHAR-----------" << std::endl;
	char	c = *s.begin();
	std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::do_int(std::string const &s) {
	std::cout << "--------DO INT-----------" << std::endl;
	int		i = std::atoi(s.c_str());
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::do_float(std::string const &s) {
	std::cout << "------DO FLOAT-------" << std::endl;
	float	f = std::atof(s.c_str());
	long long	i = static_cast<long long>(f);
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(f) << std::endl;
	}
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: " << "impossible" << std::endl;
	} else {
		std::cout << "Int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "Float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::do_double(std::string const &s) {
	std::cout << "------DO DOUBLE-------" << std::endl;
	double	d = std::atof(s.c_str());
	long long	i = static_cast<long long>(d);
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(d) << std::endl;
	}
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: " << "impossible" << std::endl;
	} else {
		std::cout << "Int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::do_other(std::string const &s) {
	std::cout << "--------DO OTHER-----------" << std::endl;
	long long	i = std::atoll(s.c_str());
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	}
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "Int: " << "impossible" << std::endl;
	} else {
		std::cout << "Int: " << static_cast<int>(i) << std::endl;
	}
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(std::atof(s.c_str())) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(std::atof(s.c_str())) << std::endl;
}