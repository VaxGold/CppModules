/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/03/23 20:23:53 by omercade         ###   ########.fr       */
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

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->_data = other.getData();
    }
    return (*this);
}

void BitcoinExchange::setData(FILE *file)
{
    //TODO
    std::string tmp;
    std::ifstream files;
    std::string line;
    bitxday aux;

    while (std::getline(files, line))
    {
        aux = this->getRef(line);
        if (this->validDate(this->parseDate(aux.date)) == 0)
            tmp = this->DateError(aux.date);
        else if (this->validValue(aux.nbc) == 0)
            tmp = this->ValueRangeError();
        else if (this->validValue(aux.nbc) == -1)
            tmp = this->NegativeValueError();
        else
            tmp = aux.date + " => " + aux.nbc + " = " + this->getValueDate(aux);
        this->_data.push(line);
        tmp.clear();
        line.clear();
    }
    return ;
}

/* yy-mm-dd => nbc = totalvalue */

std::queue<std::string> BitcoinExchange::getData() const
{
    return (this->_data);
}

dates BitcoinExchange::parseDate(std::string date)
{
    dates res;
    std::vector<std::string> aux;

    res.dd = 0;
    res.mm = 0;
    res.yy = 0;
    int start = 0;
    /* SPLITING STRING BY '-' */
    for (size_t i = 0; date.at(i) != 0; i++)
    {
        if (date.at(i) == '-')
        {
            aux.push_back(date.substr(start, i));
            start = i + 1;
        }
    }
    /* STORING */
    if (aux.size() == 3)
    {
        res.yy = atoi(aux.at(0).c_str());
        res.mm = atoi(aux.at(1).c_str());
        res.dd = atoi(aux.at(2).c_str());
    }
    return (res);
}

int BitcoinExchange::validDate(dates date)
{
    /* YEAR CHECK */
    if (date.yy < 0)
        return (0);
    
    /* MONTH CHECK */
    if (date.mm < 1 || date.mm > 12)
        return (0);

    /* DAY CHECK */
    if (date.dd < 1 || date.dd > 31)
        return (0);
    if (date.mm == 2)
    {
        if (date.yy % 4 == 0 || (date.yy % 100 == 0 && date.yy % 400 == 0))
        {
            if (date.dd > 29)
                return (0);
        }
        else
        {
            if (date.dd > 28)
                return (0);
        }
    }
    else if ((date.mm <= 7 && date.mm % 2 == 0) || (date.mm >= 8 && date.mm % 2 == 1))
    {
        if (date.dd > 30)
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
	return ("Error: bad input => " + date);
}

std::string ValueRangeError ()
{
	return ("Error: too large number.");
}

std::string NegativeValueError ()
{
	return ("Error: not a positive number.");
}

std::ostream& operator << (std::ostream &out, const BitcoinExchange &bte)
{
    std::queue<std::string> tmp = bte.getData();

    while (!tmp.empty())
    {
        out << tmp.front() << std::endl;
        tmp.pop();
    }
	return (out);
}
