/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:59:41 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/12 20:29:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class	Contact {

	private:
		std::string _fname;
		std::string _lname;
		std::string _nick;
		std::string _phone;
		std::string _secret;

	public:
		Contact(void);
		~Contact(void);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nick(void) const;
		std::string	get_phone(void) const;
		std::string get_secret(void) const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nick(std::string str);
		void		set_phone(std::string str);
		void		set_secret(std::string str);		

};

#endif