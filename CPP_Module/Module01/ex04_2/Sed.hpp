/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:44:58 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 11:49:53 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class Sed
{
	private:
		std::string	const	_filename;
		std::string	const	_s1;
		std::string	const	_s2;
		// const here means once it is initialized, it can't chage.
		// However, since it is a varaible, so it takes a copy when initializing it!

		void	_sed_next_line(std::string buff, std::ofstream& ofs);

	public:
		Sed(const std::string& f_name, const std::string& s1, const std::string& s2);
		// const in the constructor with "&" means it takes the const reference to input,
		// so you cannot change the referenced data during construction.
		~Sed(void);
		
		int		SedReplacer(void);

};

#endif