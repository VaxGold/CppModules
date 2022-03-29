/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:03:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 14:56:31 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(): _str(NULL)
{
}

ScalarConversion::ScalarConversion(std::string const & str): _str(str)
{
}

ScalarConversion::ScalarConversion(ScalarConversion const &other): _str(other.getString())
{
	*this = other;
}

ScalarConversion::~ScalarConversion()
{
}

ScalarConversion	&ScalarConversion::operator=(ScalarConversion const &other)
{
	(void)other;
	return (*this);
}

std::string const &ScalarConversion::getString() const
{
	return (this->_str);
}

void	ScalarConversion::intConversion()
{
	try
	{
		int num;
		num = static_cast <int> (std::stoi(this->_str));
		std::cout << "int: " << num << std::endl; 
	}
	catch(std::invalid_argument&)
	{
		std::cout << "int: " << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "int: " << "Non displayable" << std::endl;
	}
	return ;
}

void	ScalarConversion::charConversion()
{
	if (this->_str.length() == 1
		&& isdigit(static_cast <int> (this->_str.c_str()[0])) ==  false )
			std::cout << "char: " << static_cast <char> (this->_str.c_str()[0]) << std::endl;
	else
	{
		try
		{
			int _chararcter =  static_cast <int> (std::stoi( this->_str));
			
			if (isprint(_chararcter))
				std::cout << "char: " << "'" << static_cast <char> (_chararcter) << "'" << std::endl;
			if (_chararcter <= 32 || _chararcter >= 127)
				std::cout << "char: " << "Non displayable" << std::endl;
		}
		catch(std::invalid_argument&)
		{
			std::cout << "char: " << "impossible" << std::endl;
		}
		catch (std::out_of_range&)
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	return ;
}

void	ScalarConversion::floatConversion()
{
	try
	{
		float num;

		num = static_cast <float> (std::stof(this->_str));
		std::cout << "float: " << num;
		if (static_cast <int> (num) == num)
			std::cout << ".0";
		std::cout << "f" << std::endl;

	}
	catch(std::invalid_argument&)
	{
		std::cout << "float: " << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "float: " << "Non displayable" << std::endl;
	}
}

void	ScalarConversion::doubleConversion()
{
	try
	{
		double num;

		num = static_cast <double> (std::stod(this->_str));
		std::cout << "double: " << num;
		if (static_cast <int> (num) == num)
			std::cout << ".0";
		std::cout  << std::endl;
	}
	catch(std::invalid_argument&)
	{
		std::cout << "double: " << "impossible" << std::endl;
	}
	catch (std::out_of_range&)
	{
		std::cout << "double: " << "Non displayable" << std::endl;
	}
	return ;
}

void	ScalarConversion::showConversions()
{
	this->intConversion();
	this->charConversion();
	this->floatConversion();
	this->doubleConversion();
}