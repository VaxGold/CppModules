/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/03/22 21:10:39 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(FILE *file)
{
    setData(file);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::setData(FILE *file)
{
    //TODO
    return ;
}

std::queue<std::string> BitcoinExchange::getData() const
{
    return (this->_data);
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->_data = other.getData();
    }
    return (*this);
}

int BitcoinExchange::validDate(std::string date)
{
    int day;
    int month;
    int year;
    
    //TODO RETURNS
    //YEAR
    if (year < 0)
        return (0);
    
    //MONTH
    if (month < 1 || month > 12)
        return (0);

    //DAY
    if (day < 1 || day > 31)
        return (0);
    if (month == 2)
    {
        if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
        {
            if (day > 29)
                return (0);
        }
        else
        {
            if (day > 28)
                return (0);
        }
    }
    else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 == 1))
    {
        if (day > 30)
            return (0);
    }
    return (1);
}

int BitcoinExchange::validValue(std::string value)
{
    float n;

    n = atof(value.c_str());
    if (n < 0)
        return (-1);
    else if (n > 1000)
        return (0);
    return (1);
}

std::string DateError (std::string date)
{
	return "Error: bad input => ";
}

std::string ValueRangeError ()
{
	return "Error: too large number.";
}

std::string NegativeValueError ()
{
	return "Error: not a positive number.";
}

std::ostream& operator << (std::ostream &out, const BitcoinExchange &bte)
{
    std::queue<std::string> tmp = bte.getData();

    while (!tmp.empty())
    {
        out << tmp.front() << std::endl;
        tmp.pop();
    }
	return out;
}
