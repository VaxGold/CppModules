/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:13:01 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:41:20 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class	Dog:	public Animal
{
	public:
			Dog();
			Dog(Dog const &other);
			virtual ~Dog();

			Dog 			&operator=(Dog const &other);
			
			void			makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
