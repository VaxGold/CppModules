/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:37:09 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:43:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &other): AMateria("cure")
{
	*this = other;
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void        Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
