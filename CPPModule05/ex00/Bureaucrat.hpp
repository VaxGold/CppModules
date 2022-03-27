/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:32 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 16:31:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
	private:
			const std::string	_name;
			int					_grade;

	public:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(Bureaucrat const &other);
			virtual ~Bureaucrat();

			Bureaucrat	&operator=(Bureaucrat const &other);

			std::string	getName() const;
			int			getGrade() const;
			void		setGrade(int grade);

			void		promote();
			void		degrade();

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

std::ostream& operator << ( std::ostream &out, const Bureaucrat &bureaucrat);

#endif
