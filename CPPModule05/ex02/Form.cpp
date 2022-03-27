/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:50:28 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 14:18:20 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Standard_form"), _exgrade(150), _sgrade(150)
{
	this->_signed = false;
}

Form::Form(std::string name, int exec_grade, int sign_grade)
		: _name(name), _exgrade(exec_grade), _sgrade(sign_grade)
{
	if (_exgrade > 150)
		throw Form::GradeTooLowException();
	else if (_exgrade < 1)
		throw Form::GradeTooHighException();
	if (_sgrade > 150)
		throw Form::GradeTooLowException();
	else if (_sgrade < 1)
		throw Form::GradeTooHighException();
	this->_signed = false;
}

Form::~Form()
{
}

Form::Form(Form const &other)
		: _name(other.getName()), _exgrade(other.getExecGrade()), _sgrade(other.getSignGrade())
{
	*this = other;
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->_signed = other.getIsSigned();
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getExecGrade() const
{
	return (this->_exgrade);
}

int		Form::getSignGrade() const
{
	return (this->_sgrade);
}

bool	Form::getIsSigned() const
{
	return (this->_signed);
}

void	Form::setIsSigned(bool isSigned)
{
	this->_signed = isSigned;
}

void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
	{
		std::cout << "Bureaucrat " << bureaucrat.getName() << " cannot sign form " << this->getName() << " because the grade of the bureaucrat is too low." << std::endl;
		throw Form::GradeTooLowException();
	}
	else
		this->setIsSigned(true);	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Form: GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Form: GradeTooLowException";
}

std::ostream& operator << ( std::ostream &out, const Form &Form )
{
	out << "Form " << Form.getName() << " need grade " << Form.getExecGrade() << " to be executed and grade "
			<< Form.getSignGrade() << " to be signed, is";
	if (Form.getIsSigned() == false)
		out << " not";
	out << " signed.";
	return out;
}
