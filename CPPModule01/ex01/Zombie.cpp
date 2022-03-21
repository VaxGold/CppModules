/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:27:22 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:18:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): name("")
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->getName() << " has died... AGAIN..." << std::endl;
}

void    Zombie::announce() const
{
    std::cout << "Zombie " << this->getName() << " raises!" << std::endl;
}

std::string	Zombie::getName() const
{
	return (this->name);
}

bool	Zombie::setName(std::string newName)
{
	if (newName == "")
		return (false);
	this->name = newName;
	return (true);
}