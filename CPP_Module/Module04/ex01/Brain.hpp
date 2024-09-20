/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:04:34 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/20 17:56:56 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
private:
	/* data */
	std::string     ideas[100];
	unsigned int    _i;
public:
	Brain();
	Brain(const Brain& other);
	Brain&  operator=(const Brain& other);
	~Brain();
	
	std::string const	&getIdea(unsigned int i) const;
	void	setIdea(std::string const &str);
	
};

#endif