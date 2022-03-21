/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:24:50 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 16:53:03 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <fstream>
# include <sstream>
# include <iostream>

class	Sed
{
	private:
			static std::string	insertStr(std::string const &line, std::string const &haystack, std::string const &needle);

	public:
			Sed();
			~Sed();
			
			static void	replace(std::string const &file, std::string const &haystack, std::string const &needle);
};

#endif
