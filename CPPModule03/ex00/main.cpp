/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:07:15 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 16:35:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("CL4P-TP");
	ClapTrap	b("SH4D0W-TP");
	ClapTrap	c("T3ST-TP");
	ClapTrap	d;
	ClapTrap	e(c);

	d = a;

	std::cout << std::endl;
	a.attack("Jack");
	a.takeDamage(10);
	a.beRepaired(5);
	std::cout << std::endl;

	b.takeDamage(2);
	b.beRepaired(4);
	b.takeDamage(12);
	b.takeDamage(5);
	b.beRepaired(5);
	std::cout << std::endl;

	d.attack("stairs");
	d.beRepaired(2);
	d.takeDamage(400);
	std::cout << std::endl;

	e.attack("air");
	e.takeDamage(20000000);
	e.beRepaired(100);
	std::cout << std::endl;
}
