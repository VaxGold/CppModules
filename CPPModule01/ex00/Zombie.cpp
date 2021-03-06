/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:27:22 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:13:01 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name)
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->getName() << " has died... AGAIN..." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName( void ) const
{
	return (this->name);
}