/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:28 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 14:19:16 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("no_name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other.getName())
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		this->setGrade(other.getGrade());
	}
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void	Bureaucrat::promote()
{
	int	aux;

	aux = this->getGrade() - 1;
	if (aux > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (aux < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = aux;
}

void	Bureaucrat::degrade()
{
	int	aux;

	aux = this->getGrade() + 1;
	if (aux > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (aux < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = aux;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << "Bureaucrat " << this->getName() << " cannot sign form "
				<< form.getName() << " because is already signed." << std::endl;
		return ;
	}
	form.beSigned(*this);
	std::cout << "Bureaucrat " << this->getName() << " signs form " << form.getName() << "." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: bureaucrat: GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: bureaucrat: GradeTooLowException";
}

std::ostream& operator << ( std::ostream &out, const Bureaucrat &bureaucrat )
{
	out << "Bureaucrat " << bureaucrat.getName() << ", grade " << bureaucrat.getGrade() << ".";
	return out;
}