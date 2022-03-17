/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:22:36 by omercade          #+#    #+#             */
/*   Updated: 2022/03/14 18:44:53 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <iomanip>

std::string Contact::fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone",
	"Darkest Secret"
};

Contact::Contact()
{
    for (int i = FirstName; i <= Secret; i++)
		this->info[i] = std::string();
}

Contact::~Contact()
{
}

bool	Contact::set_info(int index)
{
    this->index = index;
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << "~ " << Contact::fields_name[i] << ":" << std::endl << "> ";
		std::getline(std::cin, this->info[i]);
	}
	size_t totalLength = 0;
	for (int i = FirstName; i <= Secret; i++)
		totalLength += this->info[i].length();
	if (totalLength == 0)
	{
		std::cout << "~ Empty contact not added !" << std::endl;
		return (false);
	}
	std::cout << "~ Contact added !" << std::endl;
	return (true);
}

void	Contact::show_header()
{
    std::cout << "|" << std::setw(10) << this->index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->info[i].length() > 10)
			std::cout << this->info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->info[i];
	}
	std::cout << "|" << std::endl;
}

void	Contact::show_info()
{
    std::cout << "~ Contact [" << this->index << "]" << std::endl;
	for (int i = FirstName; i <= Secret; i++)
	{
		std::cout << Contact::fields_name[i] << ": ";
		std::cout << this->info[i] << std::endl;
    }
}
