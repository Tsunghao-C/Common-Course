/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:34:49 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/18 23:41:31 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# define FR_HP 100
# define FR_ENG 100
# define FR_ATK 30

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
	unsigned int	_getMaxHP() const override;
	// to overide the virtual function in base class

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap	&operator=(const FragTrap &other);
	~FragTrap();
	
	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif