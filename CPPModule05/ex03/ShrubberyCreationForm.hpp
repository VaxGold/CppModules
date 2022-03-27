/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:19:03 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <string>
# include <fstream>

class	ShrubberyCreationForm : public Form
{
	private:
			std::string _target;	
			ShrubberyCreationForm();
	public:
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(ShrubberyCreationForm const &other);
			virtual ~ShrubberyCreationForm();

			ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);

			std::string				getTarget() const;
			void					setTarget(std::string const &target);

			void					execute(const Bureaucrat &bureaucrat) const;

		class FileOpenExeption
		{
			public:
			virtual const char* what() const throw ();
		};

		class FileWriteExeption
		{
			public:
			virtual const char* what() const throw ();
		};

};

#endif
