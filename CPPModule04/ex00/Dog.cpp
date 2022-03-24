/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:12:56 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:49:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog constructor." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor." << std::endl;
}

Dog::Dog(Dog const &other)
{
	*this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bark BARK BARK!!" << std::endl;
}

std::string	Dog::getType() const
{
	return(this->_type);
}

void	Dog::setType(std::string type)
{
	this->_type = type;
}