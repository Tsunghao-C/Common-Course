/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 11:15:08 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define SC_HP 100
# define SC_ENG 50
# define SC_ATK 20

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	/* data */
	int		_isGuarded;
	// to overide the virtual function in base class

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap	&operator=(const ScavTrap &other);
	virtual ~ScavTrap();
	// It's always a better practice to put "virtual" on classes that could have
	// derived other classes
	
	unsigned int	_getMaxHP() const;
	void	attack(const std::string &target);
	void	guardGate();
};

#endif