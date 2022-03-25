/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:50 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 16:27:33 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Ice: public AMateria
{
	public:
			Ice();
			Ice(Ice const &other);
			virtual ~Ice();

			Ice	&operator=(Ice const &other);

			AMateria*	clone() const;
			void		use(ICharacter& target);
};

#endif
