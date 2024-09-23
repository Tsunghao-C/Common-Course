/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:47:00 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/23 10:13:13 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:
    /* data */
public:
    Cure();
    Cure(const Cure& other);
    Cure&    operator=(const Cure& other);
    ~Cure();

    Cure*   clone() const;
    void    use(ICharacter &target);
};

#endif