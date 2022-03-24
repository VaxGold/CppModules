/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:04:05 by omercade          #+#    #+#             */
/*   Updated: 2022/03/24 19:16:39 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	protected:
			std::string     _ideas[100];
	public:
			Brain();
			Brain(Brain const &other);
			virtual ~Brain();

			Brain				&operator=(Brain const &other);
			std::string	const	*getIdeas() const;
			void				setIdeas(std::string const ideas[100]);
};

#endif
