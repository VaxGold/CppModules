/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:24 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:53:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "MeeeEeEEEeeeeEEEeeoooOOOOoooWWWwwWWW!!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return(this->_type);
}

void	WrongCat::setType(std::string type)
{
	this->_type = type;
}
