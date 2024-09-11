/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:20:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/11 19:59:49 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>

class	Contact {

	Contact (void);
	~Contact (void);

	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
};

class	PhoneBook {
	
	public:
		PhoneBook (void);
		~PhoneBook (void);

		int	getNumContacts(void);
	private:
		int	_num_contacts;
};

#endif
