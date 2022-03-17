/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:22:27 by omercade          #+#    #+#             */
/*   Updated: 2022/03/10 20:27:24 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class	Contact
{
	private:
			int					index;
			static std::string	fields_name[5];
			std::string			info[5];
			
			enum Field {
				FirstName = 0,
				LastName,
				Nickname,
				Phone,	
				Secret
			};
	public:
			Contact();
			virtual ~Contact();

			bool	set_info(int index);
			void	show_header(void);
			void	show_info(void);
};

#endif
