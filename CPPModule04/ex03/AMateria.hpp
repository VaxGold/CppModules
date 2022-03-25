/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:27:47 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:42:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	private:
			AMateria();
	protected:
			std::string	_type;
	public:
			AMateria(std::string const & type);
			AMateria(AMateria const &other);
			virtual ~AMateria();

			AMateria			&operator=(AMateria const &other);

			std::string const &	getType() const;
			void				setType(std::string const & type);
			
			virtual AMateria*	clone() const = 0;
			virtual void		use(ICharacter& target);
};

#endif

