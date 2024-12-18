/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:49:09 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 13:13:00 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
	/* data */
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog();

	void	makeSound() const;
	void	createIdea(std::string const &str);
	std::string	const &getIdea(unsigned int i) const;
};

#endif