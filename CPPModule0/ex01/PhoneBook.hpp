/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:26:53 by omercade          #+#    #+#             */
/*   Updated: 2022/03/15 20:09:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define  PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
	private:
			Contact	contacts[8];
			int		size;
			int		index;
	public:
			PhoneBook();
			virtual ~PhoneBook();

			void	show_options();
			void	add_contact();
			void	show_index();
			void	search_contact();
};

#endif
