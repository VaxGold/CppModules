/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:14:16 by omercade          #+#    #+#             */
/*   Updated: 2022/03/18 20:16:04 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{

public:

	Karen(const std::string option);
	~Karen();

	void complain();

private:

	void	debug();
	void	info();
	void	warning();
	void	error();
	void	defaultMessage();

	std::string	_level;
	int			_opt;
};

#endif
