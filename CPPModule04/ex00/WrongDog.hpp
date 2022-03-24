/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:36 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:52:39 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongDog:	public WrongAnimal
{
	public:
			WrongDog();
			WrongDog(WrongDog const &other);
			virtual ~WrongDog();

			WrongDog		&operator=(WrongDog const &other);
			
			void			makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
