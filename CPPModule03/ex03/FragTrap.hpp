/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:42:38 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:00 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string const & name);
			FragTrap(FragTrap const &other);
			virtual ~FragTrap();

			FragTrap			&operator=(FragTrap const &other);
			
			void				highFivesGuys();

			std::string const	&getName() const;
			int					getHP() const;
			int 				getEnergy() const;
			int 				getAtkDmg() const;
};

#endif
