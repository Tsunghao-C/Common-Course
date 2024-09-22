/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:39:07 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 13:12:23 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
private:
protected:
	/* data */
	std::string	_type;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal&	operator=(const AAnimal&other);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;
	// Abstraction by making a virtual function equals to zero. This makes the base class
	// not instantiate-able. The derived class must define the abstarcted function otherwise
	// it will not be aboe to instatntiate either.
	std::string const	&getType(void) const;
};

#endif