/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:06:49 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 16:30:54 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "no-name";
	this->_hp = 10;
	this->_energy = 10;
	this->_atkDmg = 0;
	std::cout << "Claptrap " <<  this->_name << " is operative with factory specifications !" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name): _name(name) 
{
	this->_hp = 10;
	this->_energy = 10;
	this->_atkDmg = 0;
	std::cout << "Claptrap " <<  this->_name << " is operative !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " <<  this->_name << " is desactivated !" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_energy = other._hp;
		this->_atkDmg = other._atkDmg;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << this->_name << " attack " << target << " , causing "
		<< this->_atkDmg << " point of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	if (this->_hp <= 0)
	{
		this->_hp = 0;
		std::cout << this->_name << " takes " << amount
			<< " points of damage, now is dead !" << std::endl;
	}
	else
	{
		std::cout << this->_name << " takes " << amount << " points of damage, now has "
			<< this->_hp << " hit points left." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	std::cout << this->_name << " recovers " << amount
		<< " points of damage, now has " << this->_hp << " hit points left." << std::endl;
}

std::string const	&ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHP() const
{
	return (this->_hp);
}

int	ClapTrap::getEnergy() const
{
	return (this->_energy);
}

int	ClapTrap::getAtkDmg() const
{
	return (this->_atkDmg);
}

void	ClapTrap::setName(std::string const & name)
{
	this->_name = name;
}

void	ClapTrap::setHP(int const amount)
{
	this->_hp = amount;
}

void	ClapTrap::setEnergy(int const amount)
{
	this->_energy = amount;
}

void	ClapTrap::setAtkDmg(int const amount)
{
	this->_atkDmg = amount;
}