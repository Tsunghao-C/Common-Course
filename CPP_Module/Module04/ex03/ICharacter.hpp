/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:07:42 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 13:48:57 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
class AMateria;

class ICharacter
{
private:
    /* data */
public:
    virtual ~ICharacter() {};
    virtual std::string const &getName() const = 0;
    virtual void    equip(AMateria *m) = 0;
    virtual void    unequip(int idx) = 0;
    virtual void    use(int idx, ICharacter& target) = 0;
};

#endif