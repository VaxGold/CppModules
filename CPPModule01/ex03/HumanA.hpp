/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:36:16 by omercade          #+#    #+#             */
/*   Updated: 2022/03/17 20:23:29 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	public:

		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );

		void	attack( void ) const;

		Weapon&	getWeapon( void ) const;

	private:

		std::string	name;
		Weapon		&weapon;
};

#endif
