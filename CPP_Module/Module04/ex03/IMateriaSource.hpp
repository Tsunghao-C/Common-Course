/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:25:05 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 13:49:31 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
class AMateria;

class IMateriaSource
{
private:
    /* data */
public:
    virtual ~IMateriaSource() {};
    virtual void    learnMateria(AMateria *m) = 0;
    virtual AMateria    *createMateria(std::string const &type) = 0;
};

#endif