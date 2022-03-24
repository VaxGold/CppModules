/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:45 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:52:55 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
			std::string	_type;

	public:
			WrongAnimal();
			WrongAnimal(std::string type);
			WrongAnimal(WrongAnimal const &other);
			virtual ~WrongAnimal();

			WrongAnimal 	&operator=(WrongAnimal const &other);

			void			makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
