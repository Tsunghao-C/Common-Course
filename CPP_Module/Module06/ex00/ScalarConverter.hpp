/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:54:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/14 15:34:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iterator>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <sstream>

class ScalarConverter
{
public:
    enum Types {
        NONE,
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        OTHER
    };
private:
    /* data */
    static Types getLiteralType(std::string const &s);
    static void do_nan();
    static void do_char(std::string const &s);
    static void do_int(std::string const &s);
    static void do_float(std::string const &s);
    static void do_double(std::string const &s);
    static void do_other(std::string const &s);
    static bool is_float(std::string const &s);
    static bool is_double(std::string const &s);
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter& operator=(ScalarConverter const &other);
    ~ScalarConverter();
public:
    static void convert(std::string s);
};

