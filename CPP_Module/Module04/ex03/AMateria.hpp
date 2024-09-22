/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:38:37 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/22 23:49:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class AMateria
{
private:
    /* data */
protected:
    std::string     _type;

public:
    AMateria(std::string const &type);
    AMateria(const AMateria& other);
    AMateria&   operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const   &getType() const;
    
    virtual AMateria*   clone() const = 0;
    virtual void    use(ICharacter  &target);
};

#endif