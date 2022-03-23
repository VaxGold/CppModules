/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:06:55 by omercade          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:28 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
			std::string	_name;
			int			_hp;
			int			_energy;
			int			_atkDmg;

	public:
			ClapTrap();
			ClapTrap(std::string const & name);
			ClapTrap(ClapTrap const &other);
			~ClapTrap();

			ClapTrap 			&operator=(ClapTrap const &other);

			void				attack(std::string const & target);
			void				takeDamage(unsigned int amount);
			void				beRepaired(unsigned int amount);

			std::string const	&getName() const;
			int					getHP() const;
			int 				getEnergy() const;
			int 				getAtkDmg() const;

			void				setName(std::string const & name);
			void				setHP(int data);
			void				setEnergy(int data);
			void				setAtkDmg(int data);
};

#endif
