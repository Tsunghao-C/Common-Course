/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 11:20:28 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	/* data */
	std::string	_Name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap	&operator=(const DiamondTrap &other);
	~DiamondTrap();

	unsigned int	_getMaxHP() const override;
	using	ScavTrap::attack;
	std::string const	&getNewName(void) const;
	void	whoAmI();
};
// The order of inheritance matters, because all the share values 
// in the base class (ClapTrap) will be override by the last initialized class
#endif