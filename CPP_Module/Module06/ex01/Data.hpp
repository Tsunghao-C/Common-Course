/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:56:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/11 11:30:33 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Data
{
private:
	/* data */
	char		_c;
	int			_i;
	float		_f;
	std::string	_s;
	void		*_addr;
	
public:
	Data();
	Data(Data const &other);
	Data&	operator=(Data const &other);
	~Data();
public:
	Data(char c);
	Data(int i);
	Data(float f);
	Data(std::string const &str);
	Data(void *ptr);
	Data(char c, int i, float f, std::string const &s, void *ptr);
public:
	void printData();
};
