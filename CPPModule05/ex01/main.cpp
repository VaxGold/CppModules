/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:42 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 14:38:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a("Hermes Conrad", 34);
	Bureaucrat b("Morgan Proctor", 19);
	Bureaucrat c("Warden Vogel", 135);
	Form f("22-JZX", 21, 42);

	try
	{
		/*---> GRADE TOO LOW EXCEPTION IN EXEC_GRADE <---*/
		Form fA("42-W", 200, 21);
		std::cout << fA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/*---> GRADE TOO HIGH EXCEPTION IN SIGN_GRADE <---*/
		Form fB("21-H", 42, 0);
		std::cout << fB << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		/*---> CANNOT SIGN FORM EXAMPLE <---*/
		std::cout << c << std::endl;
		std::cout << f << std::endl;
		c.signForm(f);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/*---> SIGN & RE-SIGN FORM EXAMPLE <---*/
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		a.signForm(f);
		b.signForm(f);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
