/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:29:31 by omercade          #+#    #+#             */
/*   Updated: 2022/03/16 18:41:26 by omercade         ###   ########.fr       */
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
			Zombie();
			virtual ~Zombie();

			void		announce(void) const;
			std::string	getName(void) const;
			bool		setName(std::string newName);
};

Zombie* zombieHorde(int N, std::string name);

#endif