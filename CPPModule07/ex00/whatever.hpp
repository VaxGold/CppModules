/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:22:23 by omercade          #+#    #+#             */
/*   Updated: 2022/03/30 14:20:13 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
 #define WHATEVER_HPP
 
# include <iostream>

template <typename T>

void	swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T>

T const & min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

template <typename T>

T const & max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif
