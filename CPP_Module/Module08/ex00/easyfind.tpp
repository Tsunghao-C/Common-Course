/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:41:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/15 14:55:22 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Container, typename T>
typename Container::value_type	easyfind(Container&	cont, T value) {
	typename    Container::value_type	target = value;
	typename	Container::iterator		it = std::find(cont.begin(), cont.end(), target);
	if (it == cont.end())
		throw (std::out_of_range("Cannot find value!"));
	return *it;
}