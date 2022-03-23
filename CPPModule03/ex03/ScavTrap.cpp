/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:29:44 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 17:00:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():  ClapTrap::ClapTrap()
{
	this->setHP(100);
	this->setEnergy(50);
	this->setAtkDmg(20);
	std::cout << "ScavTrap " <<  this->getName()
		<< " new from fabrik !" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name): ClapTrap::ClapTrap(name)
{
	this->setHP(100);
	this->setEnergy(50);
	this->setAtkDmg(20);
	std::cout << "ScavTrap " <<  this->getName()
		<< " iz redy 4 aktion !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap::ClapTrap(other.getName())
{
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName()
		<< " no mor blod 4 him !" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
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

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName()
		<< " iz on Gate Keeper mode !" << std::endl;
}

std::string const	&ScavTrap::getName() const
{
	return (this->ClapTrap::getName());
}

int	ScavTrap::getHP() const
{
	return (this->ClapTrap::getHP());
}

int	ScavTrap::getEnergy() const
{
	return (this->ClapTrap::getEnergy());
}

int	ScavTrap::getAtkDmg() const
{
	return (this->ClapTrap::getAtkDmg());
}