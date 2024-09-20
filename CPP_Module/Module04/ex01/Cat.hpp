/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:49:09 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 18:47:23 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	/* data */
	Brain	*_brain;
public:
	Cat();
	Cat(const Cat& other);
	Cat&	operator=(const Cat& other);
	~Cat();

	void	makeSound() const;
	void	createIdea(std::string const &str);
	std::string	const &getIdea(unsigned int i) const;
};

#endif