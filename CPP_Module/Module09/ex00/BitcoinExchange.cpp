/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:39:15 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/17 15:05:31 by tsuchen          ###   ########.fr       */
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
	virtual ~WrongDateFormException() throw() {}
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
	std::ifstream ifs(db_source.c_str(), std::ifstream::in);
	if (ifs.fail()) {
		std::cerr << "Error : could not open DB." << std::endl;
		exit(1);
	}
	std::map<std::string, double>   db;
	std::string     buff;
	while (std::getline(ifs, buff)) {
		std::size_t commas_pos = buff.find(',');
		if (commas_pos != std::string::npos) {
			db[buff.substr(0, commas_pos)] = std::atof(buff.substr(commas_pos + 1).c_str());
		}
	}
	return db;
}

std::string BitcoinExchange::trim(std::string const &line) {
	std::string::const_iterator	start = std::find_if(line.begin(), line.end(), std::not1(std::ptr_fun<int, int>(isspace)));
	std::string::const_iterator	end = std::find_if(line.rbegin(), line.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base();
	return start < end ? std::string(start, end) : std::string();
}

bool	BitcoinExchange::date_check(std::string const &date) {
	// check year
	std::size_t	dash_1 = date.find('-');
	if (dash_1 == std::string::npos)
		return false;
	std::string	year = date.substr(0, dash_1);
	for (std::string::const_iterator it = year.begin(); it != year.end(); ++it) {
		if (!isdigit(*it))
			return false;
	}
	int	year_i = std::atoi(year.c_str());
	if (year_i < 1970 || year_i > 9999)
		return false;
	// check month
	std::size_t dash_2 = date.find('-', dash_1 + 1);
	if (dash_2 == std::string::npos)
		return false;
	std::string month = date.substr(dash_1 + 1, dash_2 - (dash_1 + 1));
	for (std::string::const_iterator it2 = month.begin(); it2 != month.end(); ++it2) {
		if (!isdigit(*it2))
			return false;
	}
	int	month_i = std::atoi(month.c_str());
	if (month_i > 12 || month_i < 1)
		return false;
	// check day
	std::string day = date.substr(dash_2 + 1);
	for (std::string::const_iterator it3 = day.begin(); it3 != day.end(); ++it3) {
		if (!isdigit(*it3))
			return false;
	}
	int	day_i = std::atoi(day.c_str());
	if (day_i == 0 || day_i > 31)
		return false;
	if (month_i == 2) {
		if ((year_i % 4) && day_i > 28)
			return false;
		else if (day_i > 29)
			return false;
	} else if ((month_i == 4 || month_i == 6 || month_i == 9 || month_i == 11) && day_i > 30) {
		return false;
	}
	return true;
}

void	BitcoinExchange::do_conversion(std::string const &input) {
	std::ifstream ifs(input.c_str(), std::ifstream::in);
	if (ifs.fail()) {
		throw std::runtime_error("could not open file.");
	}
	std::string		buff;
	// skip the first line
	std::getline(ifs, buff);
	while (std::getline(ifs, buff)) {
		try
		{
			//parse each line
			std::size_t	pipe_pos = buff.find('|');
			if (pipe_pos != std::string::npos) {
				std::string		date = trim(buff.substr(0, pipe_pos));
				// if (date == "date")
				// 	continue;
				if (!date_check(date)) {
					throw WrongDateFormException(date);
				}
				// std::cout << "Date: " << date << " | Num: " << buff.substr(pipe_pos + 1) << std::endl;
				std::string		num = trim(buff.substr(pipe_pos + 1));
				double 		number = std::atof(num.c_str());
				if (number < 0) {
					throw NegativeNumberException();
				} else if (number > 1000) {
					throw NumberTooLargeException();
				}
				// find the corresponding rate
				std::map<std::string, double>::iterator	it;
				for (it = _db.begin(); it != _db.end(); ++it) {
					if (it->first == date) {
						break;
					}
					if (it->first > date) {
						--it;
						break;
					}
				}
				double	rate = it->second;
				// print line
				std::cout << date << " => " << number << " = " << std::fixed << std::setprecision(2) << number * rate << std::endl;
			}
			else {
				if (!date_check(trim(buff)))
					throw WrongDateFormException(trim(buff));
				std::cout << trim(buff) << " => 0 = 0" << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}