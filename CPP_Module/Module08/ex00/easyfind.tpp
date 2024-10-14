/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:41:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/14 17:56:40 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T, typename U>
typename T::value_type	easyfind(T&	container, U value) {
    size_t pos = target.find(index);
    if (pos == std::npos)
        throw (std::out_of_range)
    return pos;
}