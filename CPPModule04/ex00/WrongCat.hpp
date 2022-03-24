/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:33:19 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:53:32 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat:	public WrongAnimal
{
	public:
			WrongCat();
			WrongCat(WrongCat const &other);
			virtual ~WrongCat();

			WrongCat		&operator=(WrongCat const &other);
			
			void			makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
