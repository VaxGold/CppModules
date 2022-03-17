/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:27:31 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 18:18:51 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main()
{
    std::cout << "# Patient zero created manually #" << std::endl;
    Zombie  p_zero("Derek");
    p_zero.announce();

    std::cout << "# First spread zombie created with newZombie #" << std::endl;
    Zombie *f_spread = newZombie("Pinky");
    f_spread->announce();
    delete f_spread;

    std::cout << "# Uncontained plague created a zombie with randomChump #" << std::endl;
    randomChump("Malcolm");
    return (0);
}