/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:33:16 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 18:39:48 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Form* makeCreation(std::string const & target);
		Form* makeRequest(std::string const & target);
		Form* makePardon(std::string const & target);

	public:
            Intern();
            Intern(Intern const & other);
            virtual	~Intern();
		    
            Intern & operator= ( Intern const & other );

            Form*  makeForm( std::string const & name_form, std::string const & target_name );
		    
            class MakeFormException : public std::exception
            {
                public:
                        virtual const char * what() const throw ();
            };
};

#endif
