/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:50:34 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 16:31:23 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
			const std::string	_name;
			const int			_exgrade;
			const int			_sgrade;
			bool				_signed;
			Form();
			
	public:
			Form(std::string name, int exec_grade, int sign_grade);
			Form(Form const &other);
			virtual ~Form();

			Form	&operator=(Form const &other);

			std::string	getName() const;
			int			getExecGrade() const;
			int			getSignGrade()	const;
			bool		getIsSigned()	const;
			void		setIsSigned(bool isSigned);

			void		beSigned(const Bureaucrat &bureaucrat);

			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char *what() const throw ();
			};

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char *what() const throw ();
			};
};

std::ostream& operator << ( std::ostream &out, const Form &Form);

#endif
