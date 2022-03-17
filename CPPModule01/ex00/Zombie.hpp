/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:29:31 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 18:15:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
			std::string	name;

	public:
			Zombie(std::string name);
			virtual ~Zombie();

			void		announce(void);
			std::string	getName(void) const;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif