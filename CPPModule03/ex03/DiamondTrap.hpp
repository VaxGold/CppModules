/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:17:38 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 19:16:00 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap,  public FragTrap
{
    private:
            std::string	_name;


	public:
            DiamondTrap();
			DiamondTrap(std::string name);
			DiamondTrap(DiamondTrap const &other);
			~DiamondTrap();

			DiamondTrap			&operator=(DiamondTrap const &other);
			
            void	            attack(std::string const & target);
			void				whoAmI();

			std::string const	&getName() const;
};

#endif
