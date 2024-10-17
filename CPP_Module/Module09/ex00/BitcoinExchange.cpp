/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:39:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/17 12:16:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange::NegativeNumberException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "not a positive number.";
	}
};

class BitcoinExchange::NumberTooLargeException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "too large a number.";
	}
};

class BitcoinExchange::WrongDateFormException : public std::exception {
private:
	std::string	_msg;
public:
	WrongDateFormException(std::string const &wrong_date) {
		_msg = "bad input => " + wrong_date;
	}
	virtual const char* what() const throw() {
		return _msg.c_str();
	}
};

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {*this = other;}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const &other) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, double> BitcoinExchange::_db = BitcoinExchange::init_db(DB_PATH);

std::map<std::string, double> BitcoinExchange::init_db(std::string const &db_source) {
	std::ifstream ifs(db_source, std::ifstream::in);
	if (ifs.fail()) {
		throw std::runtime_error("could not open DB.");
	}
	std::map<std::string, double>   db;
	std::string     buff;
	while (std::getline(ifs, buff)) {
		std::size_t commas_pos = buff.find(',');
		if (commas_pos != std::string::npos) {
			db[buff.substr(0, commas_pos)] = std::stod(buff.substr(commas_pos + 1));
		}
	}
	return db;
}

std::string	BitcoinExchange::trim(std::string const &line) {
	const char* WhiteSpace = " \t\v\r";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    std::size_t end = line.find_last_not_of(WhiteSpace);
    return start == end ? std::string() : line.substr(start, end - start + 1);
}

void	BitcoinExchange::do_conversion(std::string const &input) {
	std::ifstream ifs(input, std::ifstream::in);
	if (ifs.fail()) {
		throw std::runtime_error("could not open file.");
	}
	std::string		buff;
	while (std::getline(ifs, buff)) {
		try
		{
			/* code */
			//parse each line
			std::size_t	pipe_pos = buff.find('|');
			if (pipe_pos != std::string::npos) {
				std::string		date = trim(buff.substr(0, pipe_pos));
				if (!date_check(date)) {
					throw WrongDateFormException(date);
				}
				std::string		num = trim(buff.substr(pipe_pos + 1));
				double 		number = std::stod(num);
				if (number < 0) {
					throw NegativeNumberException();
				} else if (number > 1000) {
					throw NumberTooLargeException();
				}
				// print line
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}