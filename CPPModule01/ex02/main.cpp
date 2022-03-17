/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:13:45 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 19:22:43 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	origin = "HI THIS IS BRAIN";
	std::string *ptr = &origin;
	std::string	&ref = origin;

	std::cout << "Origin memory address: " << &origin << std::endl;
	std::cout << "Pointer memory address: " << ptr << std::endl;
	std::cout << "Reference memory address: " << &ref << std::endl;

	std::cout << "Origin string: " << origin << std::endl;
	std::cout << "Pointer string: " << *ptr << std::endl;
	std::cout << "Reference string: " << ref << std::endl;
	return (0);
}
