/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:42 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:48:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Form *creation = new ShrubberyCreationForm("virtualTree");
	Form *request = new RobotomyRequestForm("Philip J. Fry");
	Form *pardon = new PresidentialPardonForm("Bender Bending Rodriguez");
	Form *ns_pardon = new PresidentialPardonForm("Dr. Zoiberg");

	Bureaucrat ba("Hermes Conrad", 34);
	Bureaucrat bb("Morgan Proctor", 19);
	Bureaucrat bc("Warden Vogel", 135);
	Bureaucrat bd("Number 1.0", 1);
	Bureaucrat be("Beholder Monster", 11);

	/* ---> ALL CORRECT SHRUBBERY_CREATION_FORM <--- */
	std::cout << std::endl;
	try
	{
		std::cout << *creation << std::endl;
		bc.signForm(*creation);
		bc.executeForm(*creation);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* ---> ALL CORRECT ROBOTOMY_REQUEST_FORM <--- */
	std::cout << std::endl;
	try
	{
		std::cout << *request << std::endl;
		ba.signForm(*request);
		ba.executeForm(*request);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* ---> ALL CORRECT PRESIDENTIAL_PARDON_FORM <--- */
	std::cout << std::endl;
	try
	{
		std::cout << *pardon << std::endl;
		bb.signForm(*pardon);
		bd.executeForm(*pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* ---> NOT SIGNED FORM TEST <--- */
	std::cout << std::endl;
	try
	{
		std::cout << *ns_pardon << std::endl;
		bd.executeForm(*ns_pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/* ---> LOW GRADE TO EXECUTE <--- */
	std::cout << std::endl;
	try
	{
		std::cout << *pardon << std::endl;
		be.executeForm(*pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete creation;
	delete request;
	delete pardon;
}