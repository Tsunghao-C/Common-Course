/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:57:54 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 11:51:57 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string a_type);
		~Weapon(void);
		std::string	const &getType(void) const;
		// The left "const &" means the return value is a const reference to a string, without
		// it, the return will be a copy of a string
		// The right "const" means you cannot change any value in this function, in this case
		// means you cannot chage ths value "_type" int the getter.
		void		setType(std::string a_type);
};	

#endif