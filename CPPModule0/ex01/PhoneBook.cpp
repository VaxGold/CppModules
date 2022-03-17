/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:26:59 by omercade          #+#    #+#             */
/*   Updated: 2022/03/15 20:22:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::show_options()
{
	std::cout << "~ Choose an option [ADD, SEARCH, EXIT]:" << std::endl;
}

void	PhoneBook::add_contact()
{	
		if (this->index == 8)
			this->index = 0;
		this->contacts[this->index].set_info(this->index + 1);
		if (this->size < 8)
			this->size++;
		this->index++;
}

void PhoneBook::show_index(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->size; i++)
		this->contacts[i].show_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	PhoneBook::search_contact()
{
	int	index;

	if (this->size == 0)
		std::cout << "~ No contacts to search... try adding one !" << std::endl;
	else
	{
		this->show_index();
		std::cout << "~ Enter index to display more information or 0 to exit" << std::endl << "> ";
		while (!(std::cin >> index) || (index < 0 || index > this->size))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "~ Invalid index\n";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->contacts[index - 1].show_info();
	}
}
