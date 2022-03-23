/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:17:32 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 19:17:18 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "no_name";
	this->ClapTrap::setName(this->getName() + "_clap_name");
	this->ClapTrap::setHP(this->FragTrap::getHP());
	this->ClapTrap::setEnergy(this->ScavTrap::getEnergy());
	this->ClapTrap::setAtkDmg(this->FragTrap::getAtkDmg());
	std::cout << "DiamondTrap " <<  this->getName()
		<< " created by default." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap (name + "_clap_name") ,  ScavTrap (name) , FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::setHP(this->FragTrap::getHP());
	this->setEnergy(50);
	this->setAtkDmg(20);
	std::cout << "DiamondTrap " <<  this->getName()
		<< " a new and very complex AI." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other): ClapTrap::ClapTrap(other.getName())
{
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTRAP " << this->getName()
		<< " is out of service, but with extra steps..." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->ClapTrap::operator= (other);
		this->ClapTrap::setHP(other.ClapTrap::getHP());
		this->ClapTrap::setEnergy(other.ClapTrap::getEnergy());
		this->ClapTrap::setAtkDmg(other.ClapTrap::getAtkDmg());
	}
	return (*this);
}

void	DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name as DiamondTrap is " << this->getName()
		<< ", but my ClapTrap name is " << this->FragTrap::getName() << "." << std::endl;
}

std::string const	&DiamondTrap::getName() const
{
	return (this->_name);
}

