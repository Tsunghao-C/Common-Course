/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:34:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/16 13:01:34 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class	Zombie {

	private:
		std::string	_name;
	
	public:
		Zombie(void);
		Zombie(const std::string& name);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
