/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:49 by omercade          #+#    #+#             */
/*   Updated: 2022/03/17 20:21:01 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
			std::string	type;

	public:
			Weapon(std::string type);
			virtual ~Weapon();

			const std::string&	getType() const;
	        bool				setType(const std::string& newType);
};

#endif
