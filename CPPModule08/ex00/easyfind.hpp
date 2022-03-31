/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:11:53 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 12:39:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class EasyFindExecption : public std::exception
{
	virtual const char* what() const throw () { return "Error: EasyFindExecption" ; }
};

template <typename T>

typename T::iterator easyFind(T &container , const int & n)
{
	typename T::iterator checker = std::find(container.begin(), container.end(), n);
	if (checker == container.end())
		throw ::EasyFindExecption();
	return (checker);
};

#endif
