/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/03/21 21:09:50 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(int fd)
{
    
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    
}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
    
}

int BitcoinExchange::validateDate(std::string date)
{
    int day;
    int month;
    int year;

    //YEAR
    if (year < 0)
    {
        throw BitcoinExchange::DateException();
        return (1);
    }
    
    //MONTH
    if (month < 1 || month > 12)
    {
        throw BitcoinExchange::DateException();
        return (1);
    }

    //DAY
    if (day < 1 || day > 31)
    {
        throw BitcoinExchange::DateException();
        return (1);
    }
    if (month == 2)
    {
        if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
        {
            if (day > 29)
            {
                throw BitcoinExchange::DateException();
                return (1);
            }
        }
        else
        {
            if (day > 28)
            {
                throw BitcoinExchange::DateException();
                return (1);
            }
        }
    }
    else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 == 1))
    {
        if (day > 30)
        {
            throw BitcoinExchange::DateException();
            return (1);
        }
    }
    return (0);
}

int BitcoinExchange::validateValue(int value)
{
    if (value < 0)
        throw BitcoinExchange::NegativeValueException();
    else if (value > 1000)
        throw BitcoinExchange::RangeValueException();
    else
        return (0);
    return (1);
}

int BitcoinExchange::validateValue(float value)
{
    if (value < 0)
        throw BitcoinExchange::NegativeValueException();
    else if (value > 1000)
        throw BitcoinExchange::RangeValueException();
    else
        return (0);
    return (1);
}

const char* BitcoinExchange::DateException::what() const throw()
{
	return "Error: bad input => ";
}

const char* BitcoinExchange::RangeValueException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::NegativeValueException::what() const throw()
{
	return "Error: not a positive number.";
}