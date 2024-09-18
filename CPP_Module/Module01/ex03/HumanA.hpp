/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:14:06 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 09:42:09 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		_name;
		const Weapon&	_weapon_a;
		// Adding const means it reference to a fixed weapon object, but the object can change
		// without const means it can change the reference to differet weapon object. Is so, we need
		// another member functin to change the reference.
	public:
		HumanA(const std::string& name, Weapon& w);
		~HumanA(void);
		void	attack(void);
};

#endif