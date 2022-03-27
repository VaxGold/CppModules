/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:19:34 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:15 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private:
			std::string _target;	
			PresidentialPardonForm();
	public:
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(PresidentialPardonForm const &other);
			virtual ~PresidentialPardonForm();

			PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);

			std::string				getTarget() const;
			void					setTarget(std::string const &target);

			void					execute(const Bureaucrat &bureaucrat) const;
};

#endif
