/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/03/23 20:44:22 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <string>
# include <fstream>
# include <queue>

struct dates
{
	int yy;
	int mm;
	int dd;
};

struct bitxday
{
	std::string date;
	std::string nbc;
};

class	BitcoinExchange
{
	private:
			std::queue<std::string> _data;
	public:
			BitcoinExchange();
			BitcoinExchange(FILE *file);
			BitcoinExchange(BitcoinExchange const &other);
			BitcoinExchange	&operator=(BitcoinExchange const &other);
			virtual ~BitcoinExchange();

			void setData(FILE *file);
			std::queue<std::string> getData() const;
			bitxday getRef(std::string line) const; //TODO
			std::string getValueDate(bitxday ref) const; //TODO
			
			dates parseDate(std::string date);

            int validDate(dates date);
            int validValue(std::string value);
			

			std::string DateError (std::string date);
			std::string ValueRangeError ();
			std::string NegativeValueError ();
};

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif