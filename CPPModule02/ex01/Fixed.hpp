/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:30:38 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 13:43:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &other);
		virtual	~Fixed();

		Fixed	&operator=(Fixed const &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
