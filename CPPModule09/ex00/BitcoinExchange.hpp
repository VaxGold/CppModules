/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/05/08 19:50:39 by omercade         ###   ########.fr       */
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

class Dates
{
	private:
			int yy;
			int mm;
			int dd;
	public:
			Dates();
			Dates(std::string str);
			Dates(Dates const &other);
			Dates &operator=(Dates const &other);
			virtual ~Dates();

			bool operator==(Dates date) const;
			bool operator!=(Dates date) const;
			bool operator<(Dates date) const;
			bool operator<=(Dates date) const;
			bool operator>(Dates date) const;
			bool operator>=(Dates date) const;

			int getYear() const;
			int getMonth() const;
			int getDay() const;
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

			bitwallet getBitwallet(std::string line) const;
			std::queue<std::string> getContainer() const;
			std::string getTotalValue(bitwallet wallet) const;

			int is_validDate(std::string date);
            int is_validValue(std::string value);
			int is_validFormat(std::string line);
};

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif


/* YYYY-MM-DD => nbc = totalvalue */

/* YYYY-MM-DD | nbc */

/* YYYY-MM-DD,value */