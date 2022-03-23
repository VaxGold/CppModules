/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:07:15 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 16:36:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	a("CL4P-TP");
	ScavTrap	b("SH4D0W-TP");
	ScavTrap	c("T3ST-TP");
	ScavTrap	d;
	ScavTrap	e(c);

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
	d.guardGate();
	std::cout << std::endl;

	e.attack("air");
	e.takeDamage(20000000);
	e.beRepaired(100);
	e.guardGate();
	std::cout << std::endl;
}
