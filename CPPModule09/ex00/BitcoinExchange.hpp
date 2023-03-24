/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/03/24 19:30:59 by omercade         ###   ########.fr       */
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

struct bitwallet
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
			BitcoinExchange(std::string route);
			BitcoinExchange(BitcoinExchange const &other);
			BitcoinExchange	&operator=(BitcoinExchange const &other);
			virtual ~BitcoinExchange();

			void setData(std::string route);
			std::queue<std::string> getData() const;
			bitwallet getRef(std::string line) const;
			std::string getValueDate(bitwallet ref) const;
			
			dates parseDate(std::string date);

            int validDate(dates date);
            int validValue(std::string value);
};

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif