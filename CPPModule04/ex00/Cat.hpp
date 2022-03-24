/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:13:14 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 16:41:21 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class	Cat:	public Animal
{
	public:
			Cat();
			Cat(Cat const &other);
			virtual ~Cat();

			Cat 			&operator=(Cat const &other);

			void			makeSound() const;
			std::string		getType() const;
			void			setType(std::string type);
};

#endif
