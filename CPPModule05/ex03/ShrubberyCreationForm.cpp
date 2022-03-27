/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:18:58 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:27:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: Form("ShrubberyCreationForm", 137, 145), _target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: Form("ShrubberyCreationForm", 137, 145), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): Form(other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->setTarget(other.getTarget());
	}
	return (*this);
}

std::string		ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void			ShrubberyCreationForm::setTarget(std::string const &target)
{
	this->_target = target;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (this->getExecGrade() < bureaucrat.getGrade())
    {
		std::cout << bureaucrat.getName() << " cannot execute " << this->getName() << ", because grade is too low." << std::endl;
        throw Form::GradeTooLowException();
	}
	else
	{
		std::string const tree[1] = 
		{
			"                                                 .\n"
			"                                      .         ;\n"
			"         .              .              ;%     ;;\n"
			"           ,           ,                :;%  %;\n"
			"            :         ;                   :;%;'     .,\n"
			"   ,.        %;     %;            ;        %;'    ,;\n"
			"     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			"      %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			"       ;%;      %;        ;%;        % ;%;  ,%;'\n"
			"        `%;.     ;%;     %;'         `;%%;.%;'\n"
			"         `:;%.    ;%%. %@;        %; ;@%;%'\n"
			"            `:%;.  :;bd%;          %;@%;'\n"
			"              `@%:.  :;%.         ;@@%;'\n"
			"                `@%.  `;@%.      ;@@%;\n"
			"                  `@%%. `@%%    ;@@%;\n"
			"                    ;@%. :@%%  %@@%;\n"
			"                      %@bd%%%bd%%:;\n"
			"                        #@%%%%%:;;\n"
			"                        %@@%%%::;\n"
			"                        %@@@%(o);  . '\n"
			"                        %@@@o%;:(.,'\n"
			"                    `.. %@@@o%::;\n"
			"                       `)@@@o%::;\n"
			"                        %@@(o)::;\n"
			"                       .%@@@@%::;\n"
			"                       ;%@@@@%::;.\n"
			"                      ;%@@@@%%:;;;.\n"
			"                  ...;%@@@@@%%:;;;;,..\n"
		};
		std::string const name_file(this->_target + "_shrubbery");
		std::ofstream file;
		file.open(name_file, std::ios::trunc);
		if (!file.is_open())
			throw ShrubberyCreationForm::FileOpenExeption();
		file << tree[0];
		if (file.bad())
		{
			file.close();
			throw FileWriteExeption();
		}
		file.close();
	}
}

const char * ShrubberyCreationForm::FileOpenExeption::what() const throw ()
{
	return "Error: ShrubberyCreationForm: FileOpenExeption";
}

const char * ShrubberyCreationForm::FileWriteExeption::what() const throw ()
{
	return "Error: ShrubberyCreationForm: FileWriteExeption";
}