/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:33 by omercade          #+#    #+#             */
/*   Updated: 2022/03/17 20:23:59 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type): type(type)
{
}

Weapon::~Weapon()
{   
}

bool    Weapon::setType(const std::string& newType)
{
    if (newType == "")
	{
		std::cout << "weapon type cannot be empty" << std::endl;
		return (false);
	}
	this->type = newType;
	return (true);
}

const std::string&   Weapon::getType() const
{
    return (this->type);
}