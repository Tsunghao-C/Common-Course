/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:35:13 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 14:01:15 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <vector>
# include <map>
# include <exception>

template <typename Container, typename T>
typename Container::value_type easyfind(Container &cont, T value);

# include "easyfind.tpp"

#endif