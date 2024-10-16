/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:41:16 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 15:19:27 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyfind(T	&cont, int i) {
	typename T::iterator	it;
	it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::out_of_range("Can not find value!");
	return it;
}