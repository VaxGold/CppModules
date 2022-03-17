/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:36:09 by omercade          #+#    #+#             */
/*   Updated: 2022/03/17 20:24:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
			std::string	name;
			Weapon		*weapon;

	public:
			HumanB(std::string name);
            ~HumanB();

            void	attack() const;

            Weapon&	getWeapon() const;
            bool	setWeapon(Weapon& newWeapon);
};

#endif
