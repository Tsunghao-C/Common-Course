/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 01:16:04 by tsuchen          ###   ########.fr       */
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
	unsigned int	_getMaxHP() const override;
	// to overide the virtual function in base class

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap	&operator=(const ScavTrap &other);
	~ScavTrap();
	
	void	attack(const std::string &target);
	void	guardGate();
};

#endif