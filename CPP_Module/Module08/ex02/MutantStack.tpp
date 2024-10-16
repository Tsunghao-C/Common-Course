/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:21:00 by tsuchen           #+#    #+#             */
/*   Updated: 2024/10/16 14:54:07 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template < typename T >
MutantStack<T>::MutantStack() {}

template < typename T >
MutantStack<T>::MutantStack(MutantStack<T> const &other) {
    *this = other;
}

template < typename T >
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const &other) {
    if (this != &other) {
        this->c = other.c;
    }
    return *this;
}

template < typename T >
MutantStack<T>::~MutantStack() {}


template < typename T >
typename MutantStack<T>::iterator   MutantStack<T>::begin() {
    return this->c.begin();
}
// "c" is the name of the underlying container in std::stack is std::deque,
// which already have iterators available to use

template < typename T >
typename MutantStack<T>::iterator   MutantStack<T>::end() {
    return this->c.end();
}

template < typename T >
typename MutantStack<T>::const_iterator   MutantStack<T>::begin() const {
    return this->c.begin();
}

template < typename T >
typename MutantStack<T>::const_iterator   MutantStack<T>::end() const {
    return this->c.end();
}