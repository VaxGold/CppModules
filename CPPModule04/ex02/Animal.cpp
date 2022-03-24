/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:12:43 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 19:46:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "undefined";
	std::cout << "Animal constructor by default." << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << "Animal constructor." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor." << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

std::string	Animal::getType() const
{
	return(this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}