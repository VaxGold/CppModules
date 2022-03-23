/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:29:50 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 16:46:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
			ScavTrap();
			ScavTrap(std::string const & name);
			ScavTrap(ScavTrap const &other);
			~ScavTrap();

			ScavTrap 			&operator=(ScavTrap const &other);
			
			void 				guardGate();

			std::string const	&getName() const;
			int					getHP() const;
			int 				getEnergy() const;
			int 				getAtkDmg() const;
};

#endif
