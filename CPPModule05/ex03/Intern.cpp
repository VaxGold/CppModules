/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:33:11 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:47:47 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & other)
{
    *this = other;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & other)
{
	(void)other;
	return *this;
}

Form* Intern::makeCreation( std::string const & target )
{
	return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRequest( std::string const & target )
{
	return (new RobotomyRequestForm(target));
}

Form* Intern::makePardon( std::string const & target )
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::MakeFormException::what() const throw ()
{
	return "Error: Intern: MakeFormException";
}

Form* Intern:: makeForm( std::string const & name_form, std::string const & target_name )
{
	Form* (Intern::*fPoint[3])(std::string const &) =
	{
		&Intern::makeCreation,
		&Intern::makeRequest,
		&Intern::makePardon
	};

	std::string const nameForm[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (nameForm[i] == name_form)
			return (this->*fPoint[i])(target_name);
	}
	throw Intern::MakeFormException();
	return (0);
}
