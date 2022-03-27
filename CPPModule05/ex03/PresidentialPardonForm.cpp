/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:19:30 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:27:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: Form("PresidentialPardonForm", 5, 25), _target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: Form("PresidentialPardonForm", 5, 25), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): Form(other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

std::string		PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void			PresidentialPardonForm::setTarget(std::string const &target)
{
	this->_target = target;
}

void    PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getExecGrade() < bureaucrat.getGrade())
	{
		std::cout << bureaucrat.getName() << " cannot execute " << this->getName() << ", because grade is too low." << std::endl;
        throw Form::GradeTooLowException();
	}
	else
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
