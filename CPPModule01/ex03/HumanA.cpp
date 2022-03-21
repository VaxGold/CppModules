/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:58 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:20:19 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with his " << this->getWeapon().getType()
		<< std::endl;
}

Weapon&	HumanA::getWeapon() const
{
	return (this->weapon);
}
