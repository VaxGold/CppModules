/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:27:31 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 19:11:47 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	announceAll( Zombie *zombieHorde, int N)
{
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].announce();
	}
}

int     main()
{
    int hordeLen = 7;

    std::cout << "# Creating the HORDE! #" << std::endl;
	Zombie	*horde = zombieHorde(hordeLen, "Paches");
	announceAll(horde, hordeLen);
	delete [] horde;
    return (0);
}