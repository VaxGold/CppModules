/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/03/21 21:23:30 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class	BitcoinExchange
{
	private:
			

	public:
			BitcoinExchange();
			BitcoinExchange(FILE *file);
			BitcoinExchange(BitcoinExchange const &other);
			virtual ~BitcoinExchange();

			BitcoinExchange	&operator=(BitcoinExchange const &other);

            int validateDate(std::string date);
            int validateValue(int value);
            int validateValue(float value);
            
			class DateException : public std::exception
			{
				public:
					virtual const char *what() const throw ();
			};

            class RangeValueException : public std::exception
			{
				public:
					virtual const char *what() const throw ();
			};

            class NegativeValueException : public std::exception
			{
				public:
					virtual const char *what() const throw ();
			};
};

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif