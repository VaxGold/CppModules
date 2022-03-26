/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:03:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 19:17:48 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = "ideas";
	}
	std::cout << "Brain constructor." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor." << std::endl;
}

Brain::Brain(Brain const &other)
{
	*this = other;
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];	
		//this->setIdeas(other.getIdeas());
	}
	return (*this);
}

std::string const 	*Brain::getIdeas() const
{
	return(&this->_ideas[100]);
}

void	Brain::setIdeas(std::string const ideas[100])
{
	for(size_t i = 0 ; i < 100 ; i++)
	{
		this->_ideas[i] = ideas[i];
	}
}
