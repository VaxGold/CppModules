/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:50:59 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "undefined";
	std::cout << "WrongAnimal constructor by default." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->_type = type;
	std::cout << "WrongAnimal constructor." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[ * Unintelligible Noises * ]" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
