/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:01:08 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:35:34 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
			std::string _name;
			AMateria	*_skills[4];
			size_t		_skSize;
	public:
			Character();
			Character(std::string const & name);
			Character(Character const &other);
			~Character();

			Character	&operator=(Character const &other);

			std::string const &	getName() const;
			void				setName(std::string const & name);
			
			void				equip(AMateria *m);
			void				unequip(int idx);
			void				use(int idx, ICharacter& target);
};

#endif