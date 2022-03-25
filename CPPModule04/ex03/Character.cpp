/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:01:16 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:37:27 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "Nameless";
	this->_skSize = 0;
	for (size_t i = 0; i < 4; i++)
		this->_skills[i] = 0;
}

Character::Character(std::string const & name)
{
	this->_name = name;
	this->_skSize = 0;
	for (size_t i = 0; i < 4; i++)
		this->_skills[i] = 0;
}

Character::~Character()
{
	for(size_t i = 0; i < this->_skSize; i++)
	{
		if (this->_skills[i] != 0)
			this->_skills[i] = 0;
	}
}

Character::Character(Character const &other)
{
	*this = other;
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		for(size_t i = 0; i < 4; i++)
		{
			if (this->_skills[i] != 0)
				this->_skills[i] = 0;
		}
		this->setName(other.getName());
		this->_skSize = other._skSize;
		for(size_t i = 0; i < this->_skSize; i++)
			this->_skills[i] = other._skills[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return(this->_name);
}

void	Character::setName(std::string const & name)
{
	this->_name = name;
}

void    Character::equip(AMateria *m)
{
	if (this->_skSize == 3)
		return ;
	this->_skills[_skSize++] = m;
}

void    Character::unequip(int idx)
{
	if (this->_skSize == 0)
		return ;
	this->_skills[idx] = 0;
	for (size_t i = idx; i < this->_skSize - 1; i++)
	{
		this->_skills[i] = this->_skills[i + 1];
		this->_skills[i + 1] = 0;
	}
	this->_skSize--;
}

void    Character::use(int idx, ICharacter& target)
{
	if (idx + 1 > (int)this->_skSize || idx < 0)
		return ;
	this->_skills[idx]->use(target);
}
