/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:17:47 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/10 13:01:05 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::do_nan(std::string const &s) {
	// std::cout << "--------DO NAN-----------" << std::endl;
	(void)s;
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << "nan" << "f" << std::endl;
	std::cout << "Double: " << "nan" << std::endl;
	// if (s == "nan" || s == "nanf") {
	// 	std::cout << "Float: " << "nan" << "f" << std::endl;
	// 	std::cout << "Double: " << "nan" << std::endl;
	// } else if (s == "+inf" || "+inff") {
	// 	std::cout << "Float: " << "+inf" << "f" << std::endl;
	// 	std::cout << "Double: " << "+inf" << std::endl;
	// } else {
	// 	std::cout << "Float: " << "-inf" << "f" << std::endl;
	// 	std::cout << "Double: " << "-inf" << std::endl;
	// }
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
	if (i < 0 || i > 127) {
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
	int		i = static_cast<int>(f);
	if (i < 0 || i > 127) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::do_double(std::string const &s) {
	std::cout << "------DO DOUBLE-------" << std::endl;
	double	d = std::atof(s.c_str());
	int		i = static_cast<int>(d);
	if (i < 0 || i > 127) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::do_other(std::string const &s) {
	std::cout << "--------DO OTHER-----------" << std::endl;
	int		i = std::atoi(s.c_str());
	if (i < 0 || i > 127) {
		std::cout << "Char: " << "impossible" << std::endl;
	} else if (i < 32) {
		std::cout << "Char: " << "Not displayable" << std::endl;
	} else {
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	}
	if (s != std::to_string(i)) {
		std::cout << "Int: " << "impossible" << std::endl;
	} else {
		std::cout << "Int: " << i << std::endl;
	}
	std::cout << "Float: " << std::fixed << std::setprecision(2) << static_cast<float>(std::atof(s.c_str())) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(std::atof(s.c_str())) << std::endl;
}