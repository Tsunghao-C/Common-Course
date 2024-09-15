/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:44:58 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/15 17:35:21 by tsuchen          ###   ########.fr       */
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
		std::string		_filename;
		std::string		_s1;
		std::string		_s2;

		void	sed_next_line(std::string buff, std::ofstream& ofs);

	public:
		Sed(const std::string& f_name, const std::string& s1, const std::string& s2);
		~Sed(void);
		
		int		SedReplacer(void);

};

#endif