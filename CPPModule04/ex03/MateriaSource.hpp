/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:02:37 by omercade          #+#    #+#             */
/*   Updated: 2022/03/25 19:49:34 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
			AMateria	*_elements[4];
			size_t			_size;
	public:
			MateriaSource();
			MateriaSource(MateriaSource const &other);
			~MateriaSource();

			MateriaSource	&operator=(MateriaSource const &other);

			void		learnMateria(AMateria *m);
			AMateria*	createMateria(std::string const & type);
};

#endif
