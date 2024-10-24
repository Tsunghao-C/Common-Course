/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:20:51 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 15:38:58 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include "Contact.hpp"

class	PhoneBook {
	
	private:
		int		_index;
		Contact	_contacts[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void) const;
		void	printContact(void) const;

};

#endif
