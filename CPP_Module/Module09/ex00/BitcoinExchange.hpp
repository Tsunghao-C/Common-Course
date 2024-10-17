/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:10:40 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/17 11:53:32 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <algorithm>
# include <exception>
# include <cstdlib>
# define DB_PATH "./cpp_09/data.csv"

class BitcoinExchange
{
private:
	/* data */
	static std::map<std::string, double>	_db;
	static std::map<std::string, double>	init_db(std::string const &db_source);
	static std::string		trim(std::string const &line);
	static bool		date_check(std::string const &date);
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange& operator=(BitcoinExchange const &other);
	~BitcoinExchange();	
public:
	static void	do_conversion(std::string const &input);
public:
	class NegativeNumberException;
	class NumberTooLargeException;
	class WrongDateFormException;
};

#endif