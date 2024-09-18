/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:17:33 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 13:51:02 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define DFT_HP 10
# define DFT_EP 10
# define DFT_DM 0

# include <iostream>
# include <string>

class ClapTrap
{
private:
	/* data */
	std::string		_Name;
	unsigned int	_HP;
	unsigned int	_ENG;
	unsigned int	_ATK;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(const ClapTrap& other);
	~ClapTrap(void);

	std::string const	&getName(void) const;
	unsigned int	getHP(void) const;
	unsigned int	getENG(void) const;
	unsigned int	getATK(void) const;
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif