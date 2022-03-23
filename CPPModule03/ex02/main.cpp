/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:05:39 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 17:06:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap	a("CL4P-TP");
	FragTrap	b("SH4D0W-TP");
	FragTrap	c("T3ST-TP");
	FragTrap	d;
	FragTrap	e(c);

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
	d.highFivesGuys();
	std::cout << std::endl;

	e.attack("air");
	e.takeDamage(20000000);
	e.beRepaired(100);
	e.highFivesGuys();
	std::cout << std::endl;
}
