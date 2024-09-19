/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:17:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 15:32:37 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define CL_HP 10
# define CL_ENG 10
# define CL_ATK 0

# include <iostream>
# include <string>

class ClapTrap
{
private:

protected:
	/* data */
	std::string		_Name;
	unsigned int	_HP;
	unsigned int	_ENG;
	unsigned int	_ATK;

	virtual	unsigned int	_getMaxHP() const;
	// A virtual function that can be overridden by derived classes

public:
	ClapTrap(void);
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	virtual ~ClapTrap(void);
	// It is a better practice to make the base destructor "virtual"
	// to make sure even if you call destructor from base class level, the destructors
	// are already overwritten by the derived class'es destructor so all the 
	// derived objects are destructed

	std::string const	&getName(void) const;
	unsigned int	getHP(void) const;
	unsigned int	getENG(void) const;
	unsigned int	getATK(void) const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif