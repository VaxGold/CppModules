/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:13:10 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:49:21 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor." << std::endl;
}

Cat::Cat(Cat const &other)
{
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
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