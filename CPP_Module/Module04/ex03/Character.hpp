/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:19:06 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 13:54:51 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	/* data */
	std::string	_name;
	AMateria	*_inv[4];
	
public:
	Character(std::string const &name);
	Character(const Character& other);
	Character&	operator=(const Character& other);
	~Character();
	
	std::string	const &getName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);	
};

#endif