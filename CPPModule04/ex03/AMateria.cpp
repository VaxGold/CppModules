/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:27:39 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:33:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return(this->_type);
}

void	AMateria::setType(std::string const & type)
{
	this->_type = type;
}

void        AMateria::use(ICharacter& target)
{
    std::cout << "* do nothing to " << target.getName() << " *" << std::endl;
}
