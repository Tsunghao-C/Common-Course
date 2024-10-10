/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:54:57 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/10 12:38:03 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class ScalarConverter
{
public:
    enum Types {
        LIMITS,
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        OTHER
    };
private:
    /* data */
    static Types getLiteralType(std::string const &s);
    static void do_nan(std::string const &s);
    static void do_char(std::string const &s);
    static void do_int(std::string const &s);
    static void do_float(std::string const &s);
    static void do_double(std::string const &s);
    static void do_other(std::string const &s);
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter& operator=(ScalarConverter const &other);
    ~ScalarConverter();
public:
    static void convert(std::string s);
};

