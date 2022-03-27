/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:19:14 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:27:45 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
		: Form("RobotomyRequestForm", 45, 72), _target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: Form("RobotomyRequestForm", 45, 72), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): Form(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void			RobotomyRequestForm::setTarget(std::string const &target)
{
	this->_target = target;
}

void    RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
    if (this->getExecGrade() < bureaucrat.getGrade())
    {
		std::cout << bureaucrat.getName() << " cannot execute " << this->getName() << ", because grade is too low." << std::endl;
        throw Form::GradeTooLowException();
	}
    else
    {
        int seed = 0;
        std::cout << "[ * Drilling noises * ]" << std::endl;
        srand( time(0) );
        seed = ( rand() % 100 );
        if ( seed > 50 )
            std::cout << this->getTarget() << " has been robotomized." << std::endl;
        else
            std::cout << "It's a failure !" << std::endl;
    }
}
