/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:53 by omercade          #+#    #+#             */
/*   Updated: 2022/03/30 20:13:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

class EasyFindExecption : public std::exception
{
	virtual const char* what() const throw () { return "Error: EasyFindExecption" ; }
};

template <typename T>

typename T::iterator easyFind(T &container , const int & n)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end())
		throw ::EasyFindExecption();
	return iter;
};

#endif
