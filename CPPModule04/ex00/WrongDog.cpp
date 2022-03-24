/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:32 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:53:14 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(): WrongAnimal("WrongDog")
{
    std::cout << "WrongDog constructor." << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor." << std::endl;
}

WrongDog::WrongDog(WrongDog const &other)
{
	*this = other;
}

WrongDog &WrongDog::operator=(WrongDog const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

void	WrongDog::makeSound() const
{
	std::cout << "Bark BARK BARK!!" << std::endl;
}

std::string	WrongDog::getType() const
{
	return(this->_type);
}

void	WrongDog::setType(std::string type)
{
	this->_type = type;
}
