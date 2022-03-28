/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:03:59 by omercade          #+#    #+#             */
/*   Updated: 2022/03/28 19:15:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>

class	ScalarConversion
{
	private:
			const std::string	_str;
			ScalarConversion();
			void displayInt();
			void displayChar();
			void displayFloat();
			void displayDouble();

	public:
			ScalarConversion(std::string const & str);
			ScalarConversion(ScalarConversion const &other);
			~ScalarConversion();
			ScalarConversion	&operator=(ScalarConversion const &other);

			std::string const	&getString() const;
			
			void				display();
};

#endif