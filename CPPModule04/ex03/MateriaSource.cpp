/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:02:43 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:50:20 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->_elements[i] = 0;
	this->_size = 0;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < this->_size; i++)
		delete this->_elements[i];
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < this->_size; i++)
		{
			if (this->_elements[i] != 0)
				delete this->_elements[i];
		}
		this->_size = other._size;
		for (size_t i = 0; i < this->_size; i++)
		{
			if (this->_elements[i] != 0)
				this->_elements[i] = other._elements[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (this->_size == 4)
		return ;
	if (m != 0)
		this->_elements[this->_size++] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->_elements[i]->getType() == type)
			return (this->_elements[i]);
	}
	return (0);
}
