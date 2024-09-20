/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:39:07 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 15:40:43 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
private:
protected:
	/* data */
	std::string	_type;

public:
	Animal();
	Animal(const Animal& other);
	Animal&	operator=(const Animal&other);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string const	&getType(void) const;
};

#endif