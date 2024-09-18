/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:51:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 09:50:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string& f_name, const std::string& s1, const std::string& s2) : _filename(f_name), _s1(s1), _s2(s2) {
	std::cout << "Sed object initiated" << std::endl;
}

Sed::~Sed(void) {
	std::cout << "Sed object destroyed" << std::endl;
}

int Sed::SedReplacer(void) {
	if (this->_s1.size() == 0) {
		std::cerr << "Error: target string cannot be empty" << std::endl;
		return EXIT_FAILURE;
	}
	std::ifstream   ifs(this->_filename, std::ifstream::in);
	if (ifs.fail()) {
		std::cerr << "Error: Failed to open infile " << this->_filename << std::endl;
		return EXIT_FAILURE;
	}
	std::ofstream   ofs(this->_filename + ".replace", std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail()) {
		std::cerr << "Error: Failed to open outfile" << this->_filename + ".replace" << std::endl;
		return EXIT_FAILURE;
	}
	std::string     buff;
	while (std::getline(ifs, buff)) {
		this->_sed_next_line(buff, ofs);
		if (!ifs.eof())
			ofs << std::endl;
	}
	return EXIT_SUCCESS;
}

void	Sed::_sed_next_line(std::string buff, std::ofstream& ofs) {
	std::size_t	pos = 0;
	std::size_t	found = buff.find(this->_s1);
	while (found != std::string::npos) {
		ofs << buff.substr(pos, found - pos) << this->_s2;
		found += this->_s1.length();
		pos = found;
		found = buff.find(this->_s1, found);
	}
	ofs << buff.substr(pos);
}