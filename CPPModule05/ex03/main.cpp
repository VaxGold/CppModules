/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:42 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:55:25 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	Form* rrf;
	Bureaucrat ba("Hermes Conrad", 34);
	
	/* ---> Right form <--- */
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *rrf << std::endl;
	ba.signForm(*rrf);
	ba.executeForm(*rrf);
	delete rrf;

	/* ---> Wrong form <--- */
	std::cout << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("22-JZX", "Philip J. Fry");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}