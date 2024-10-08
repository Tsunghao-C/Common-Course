/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:17:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/19 16:29:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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

	std::string const	&getName(void) const;
	unsigned int	getHP(void) const;
	unsigned int	getENG(void) const;
	unsigned int	getATK(void) const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif