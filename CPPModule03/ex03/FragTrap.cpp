/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:42:50 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 19:10:12 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():  ClapTrap::ClapTrap()
{
	this->setHP(100);
	this->setEnergy(100);
	this->setAtkDmg(30);
	std::cout << "FRAGTRAP " <<  this->getName()
		<< " DIRECT FROM FACTORY !" << std::endl;
}

FragTrap::FragTrap(std::string const & name): ClapTrap::ClapTrap(name)
{
	this->setHP(100);
	this->setEnergy(50);
	this->setAtkDmg(20);
	std::cout << "FRAGTRAP " <<  this->getName()
		<< " NEW AND SHINNY !" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap::ClapTrap(other.getName())
{
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAGTRAP " << this->getName()
		<< " IS DESTROYED WITH A BIG EXPLOSION ! ! !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHP(other.getHP());
		this->setEnergy(other.getEnergy());
		this->setAtkDmg(other.getAtkDmg());
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FRAGTRAP " << this->getName()
		<< " SOMEONE HIGH FIVE ? !" << std::endl;
}

std::string const	&FragTrap::getName() const
{
	return (this->ClapTrap::getName());
}

int	FragTrap::getHP() const
{
	return (this->ClapTrap::getHP());
}

int	FragTrap::getEnergy() const
{
	return (this->ClapTrap::getEnergy());
}

int	FragTrap::getAtkDmg() const
{
	return (this->ClapTrap::getAtkDmg());
}
