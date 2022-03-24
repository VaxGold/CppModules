/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:12:47 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:47:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
			std::string	_type;

	public:
			Animal();
			Animal(std::string type);
			Animal(Animal const &other);
			virtual ~Animal();

			Animal 			&operator=(Animal const &other);

			virtual void	makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
