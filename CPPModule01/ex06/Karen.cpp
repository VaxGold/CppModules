/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:11 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:31:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

Karen::Karen(std::string option): _level(option)
{
}

Karen::~Karen()
{
}

int		Karen::levelOption()
{
	std::string functLevel[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (this->_level == functLevel[i])
			return (i);
	}
	return (42);
}

void	Karen::complain()
{
    _opt = this->levelOption();
	switch (this->_opt)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			this->defaultMessage();
	}
}

void	Karen::error()
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable, I want to speak to the manager now."
    << std::endl << std::endl;
}

void	Karen::warning()
{
	std::cout << "[WARNING]" << std::endl
        << "I think I deserve to have some extra bacon for free." 
        "I've been coming here for years and you just started working here last month."
        << std::endl << std::endl;
}

void	Karen::info()
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon "
		"cost more money. You don't put enough! If you did I would not have to "
		"ask for it!" << std::endl << std::endl;
}

void	Karen::debug()
{
	std::cout << "[DEBUG]" << std::endl
    << "I love to get extra bacon for my 7X L-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
    << std::endl << std::endl;
}

void	Karen::defaultMessage()
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
