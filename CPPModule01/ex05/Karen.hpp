/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:13:04 by omercade          #+#    #+#             */
/*   Updated: 2022/03/18 17:22:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{
public:

	Karen();
	~Karen();

	void complain(std::string level);

private:

	void	debug();
	void	info();
	void	warning();
	void	error();
};

#endif
