/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:34:59 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/13 11:17:33 by tsuchen          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		Zombie* newZombie(std::string name);
		void	randomChump(std::string name);
};
#endif