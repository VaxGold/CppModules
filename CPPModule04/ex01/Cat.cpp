/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:13:10 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 19:20:14 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor." << std::endl;
	delete  this->_brain;
}

Cat::Cat(Cat const &other)
{
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		delete this->_brain;
		this->_brain = new Brain();
		this->setType(other.getType());
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "MeeeEeEEEeeeeEEEeeoooOOOOoooWWWwwWWW!!" << std::endl;
}

std::string	Cat::getType() const
{
	return(this->_type);
}

void	Cat::setType(std::string type)
{
	this->_type = type;
}