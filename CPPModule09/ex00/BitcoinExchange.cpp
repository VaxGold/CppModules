/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/03/29 21:14:13 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string route)
{
    std::ifstream file(route);
    std::string line;
    std::string str;
    bitwallet tmp;

    while (std::getline(file, line))
    {
        if (is_validFormat(line))
        {
            tmp = getBitwallet(line);
            if (!this->is_validDate(tmp.date))
                str = "Error: bad input => " + tmp.date;
            else if (this->is_validValue(tmp.nbc) == 0)
                str = "Error: too large number.";
            else if (this->is_validValue(tmp.nbc) == -1)
                str = "Error: not a positive number.";
            else
                str = tmp.date + " => " + tmp.nbc + " = " + this->getTotalValue(tmp);
            this->_data.push(str);
            str.clear();
            line.clear();
        }
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->_data = other.getContainer();
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

bitwallet BitcoinExchange::getBitwallet(std::string line) const
{
    bitwallet res;
    res.date = "";
    res.nbc = "";

    size_t i = 0;
    size_t start = 0;

    while (line[i] != ' ')
        i++;
    res.date = line.substr(0, i);
    if (line[++i] != '|')
        return res;
    if (line[++i] != ' ')
        return res;
    if (line[++i] == 0)
        return res;
    start = i;
    while (line[i] != 0)
        i++;
    res.nbc = line.substr(start, line.length() - start);
    return res;
}

std::queue<std::string> BitcoinExchange::getContainer() const
{
    return (this->_data);
}

std::string BitcoinExchange::getTotalValue(bitwallet ref) const
{
    std::ifstream file("data.csv");
    std::string line;
    float value = 0;

    while (std::getline(file, line))
    {
        size_t i = 0;
        while (line.at(i) != ',')
            i++;
        if (strcmp(line.substr(0,i).c_str(), ref.date.c_str()) == 1)
            break ;
        value = atof(line.substr(i + 1, line.length() - i - 1).c_str());
        if (strcmp(line.substr(0,i).c_str(), ref.date.c_str()) == 0)
            break ;
        line.clear();
    }
    value = atof(ref.nbc.c_str()) * value;
    return (std::to_string(value));
}

int BitcoinExchange::is_validDate(std::string date)
{
    dates calendar = ft_strDate(date);

    /* YEAR CHECK */
    if (calendar.yy < 0)
        return (0);
    
    /* MONTH CHECK */
    if (calendar.mm < 1 || calendar.mm > 12)
        return (0);

    /* DAY CHECK */
    if (calendar.dd < 1 || calendar.dd > 31)
        return (0);
    if (calendar.mm == 2)
    {
        if (calendar.yy % 4 == 0 || (calendar.yy % 100 == 0 && calendar.yy % 400 == 0))
        {
            if (calendar.dd > 29)
                return (0);
        }
        else
        {
            if (calendar.dd > 28)
                return (0);
        }
    }
    else if ((calendar.mm <= 7 && calendar.mm % 2 == 0) || (calendar.mm >= 8 && calendar.mm % 2 == 1))
    {
        if (calendar.dd > 30)
            return (0);
    }
    return (1);
}

int BitcoinExchange::is_validValue(std::string value)
{
    float n;

    n = atof(value.c_str());
    if (n < 0)
        return -1;
    else if (n > 1000)
        return 0;
    return 1;
}

int BitcoinExchange::is_validFormat(std::string line)
{
    size_t i = 0;

    return 1;
    while (line.at(i) != ' ')
    {
        if (!isnumber(line.at(i) && line.at(i) != '-'))
            return 0;
        i++;
    }
    if (line.at(++i) != '|')
        return 0;
    if (line.at(++i) != ' ')
        return 0;
    while (line.at(i) != 0)
    {
        if (!isnumber(line.at(i) && line.at(i) != '.'))
            return 0;
        i++;
    }
    return 1;
}

dates ft_strDate(std::string date)
{
    dates res;

    res.dd = 0;
    res.mm = 0;
    res.yy = 0;

    int start = 0;
    size_t i = 0;

    while (date.at(i) != '-')
        i++;
    res.yy = atoi(date.substr(start, i - start).c_str());
    start = ++i;
    while (date.at(i) != '-')
        i++;
    res.mm = atoi(date.substr(start, i - start).c_str());
    start = ++i;
    while (i < date.length())
        i++;
    res.dd = atoi(date.substr(start, date.length() - start).c_str());
    return (res);
}

std::ostream& operator << (std::ostream &out, const BitcoinExchange &bte)
{
    std::queue<std::string> tmp = bte.getContainer();

    while (!tmp.empty())
    {
        out << tmp.front() << std::endl;
        tmp.pop();
    }
	return (out);
}
