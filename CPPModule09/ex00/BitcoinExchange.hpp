/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/03/22 21:08:21 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <queue>

// struct bitdata
// {
// 	int dd;
// 	int mm;
// 	int yy;
// 	float nbc;
// 	float value;
// };


class	BitcoinExchange
{
	private:
			std::queue<std::string> _data;
	public:
			BitcoinExchange();
			BitcoinExchange(FILE *file);
			BitcoinExchange(BitcoinExchange const &other);
			virtual ~BitcoinExchange();

			void setData(FILE *file);
			std::queue<std::string> getData() const;

            int validDate(std::string date);
            int validValue(std::string value);
			
			BitcoinExchange	&operator=(BitcoinExchange const &other);

			std::string DateError (std::string date);
			std::string ValueRangeError ();
			std::string NegativeValueError ();
            
			//Excepciones
			// class DateException : public std::exception
			// {
			// 	public:
			// 		virtual const char *what() const throw ();
			// };

            // class RangeValueException : public std::exception
			// {
			// 	public:
			// 		virtual const char *what() const throw ();
			// };

            // class NegativeValueException : public std::exception
			// {
			// 	public:
			// 		virtual const char *what() const throw ();
			// };
};

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif