/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:41 by omercade          #+#    #+#             */
/*   Updated: 2023/03/29 21:14:21 by omercade         ###   ########.fr       */
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

			bitwallet getBitwallet(std::string line) const;
			std::queue<std::string> getContainer() const;
			std::string getTotalValue(bitwallet wallet) const;

			int is_validDate(std::string date);
            int is_validValue(std::string value);
			int is_validFormat(std::string line); //TODO
};

dates ft_strDate(std::string date);

std::ostream& operator << ( std::ostream &out, const BitcoinExchange &bte);

#endif


/* YYYY-MM-DD => nbc = totalvalue */

/* YYYY-MM-DD | nbc */

/* YYYY-MM-DD,value */