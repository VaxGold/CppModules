/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:36:04 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:21:45 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name ): name(name), weapon(nullptr)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with his " << this->getWeapon().getType()
			<< std::endl;
	}
	else
	{
		std::cout << this->name
			<< " is totally disarmed... throws a sucker punch " << std::endl;
	}
}

Weapon&	HumanB::getWeapon() const
{
	return (*(this->weapon));
}

bool	HumanB::setWeapon(Weapon& newWeapon)
{
	if (newWeapon.getType() == "")
	{
		std::cerr << "Weapon cannot be nothing, it needs a type" << std::endl;
		return (false);
	}
	this->weapon = &newWeapon;
	return (true);
}
