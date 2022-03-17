/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:57:41 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 18:15:32 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	opt;
	bool		esig;

	esig = false;
	while (!esig)
	{
		pb.show_options();
		std::cout << "> ";
		std::getline(std::cin, opt);
		if (opt == "ADD" || opt == "add")
			pb.add_contact();
		else if (opt == "SEARCH" || opt == "search")
			pb.search_contact();
		else if (opt == "EXIT" || opt == "exit")
			esig = true;
		else
			std::cout << "~ Wrong option... Try again !" << std::endl;
	}
	return (0);
}
