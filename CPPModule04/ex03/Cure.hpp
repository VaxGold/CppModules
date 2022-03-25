/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:59 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 16:27:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
			Cure();
			Cure(Cure const &other);
			virtual ~Cure();

			Cure	&operator=(Cure const &other);

			AMateria*	clone() const;
			void		use(ICharacter& target);
};

#endif
