/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:18:03 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 19:16:06 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	a("CL4P-TP");
	DiamondTrap	b("SH4D0W-TP");
	DiamondTrap	c("T3ST-TP");
	DiamondTrap	d;
	DiamondTrap	e(c);

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
	d.whoAmI();
	std::cout << std::endl;

	e.attack("air");
	e.takeDamage(20000000);
	e.beRepaired(100);
	e.whoAmI();
	std::cout << std::endl;
}
