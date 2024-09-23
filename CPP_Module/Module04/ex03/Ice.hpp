/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:47:00 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 10:12:30 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:
    /* data */
public:
    Ice();
    Ice(const Ice& other);
    Ice&    operator=(const Ice& other);
    ~Ice();

    Ice*   clone() const;
    void    use(ICharacter &target);
};

#endif