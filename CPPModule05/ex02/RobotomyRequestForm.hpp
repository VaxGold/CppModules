/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:19:20 by omercade          #+#    #+#             */
/*   Updated: 2022/03/27 17:35:11 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
			std::string _target;	
			RobotomyRequestForm();
	public:
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(RobotomyRequestForm const &other);
			virtual ~RobotomyRequestForm();

			RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);

			std::string				getTarget() const;
			void					setTarget(std::string const &target);

			void					execute(const Bureaucrat &bureaucrat) const;
};

#endif
