/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/03/24 19:40:36 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(std::string route)
{
    setData(route);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        this->_data = other.getData();
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::setData(std::string route)
{
    std::ifstream file(route);
    std::string tmp;
    std::string line;
    bitwallet aux;

    while (std::getline(file, line))
    {
        aux = this->getRef(line);
        if (this->validDate(this->parseDate(aux.date)) == 0)
            tmp = "Error: bad input => " + aux.date;
        else if (this->validValue(aux.nbc) == 0)
            tmp = "Error: too large number.";
        else if (this->validValue(aux.nbc) == -1)
            tmp = "Error: not a positive number.";
        else
            tmp = aux.date + " => " + aux.nbc + " = " + this->getValueDate(aux);
        this->_data.push(tmp);
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

bitwallet BitcoinExchange::getRef(std::string line) const
{
    bitwallet res;
    res.date = "0000-00-00";
    res.nbc = "";
    int i = 0;
    int aux = 0;

    while (line[i] != ' ')
        i++;
    res.date = line.substr(0, i);
    if (line[++i] != '|')
        return res;
    if (line[i] != ' ')
        return res;
    aux = i;
    while (line[i] != 0)
        i++;
    res.nbc = line.substr(aux, line.length() - aux);
    return res;
}

std::string BitcoinExchange::getValueDate(bitwallet ref) const
{
    std::ifstream file("data.csv");
    std::string line;
    float value = 0;
    int i;

    while (std::getline(file, line))
    {
        if (strcmp(ref.date.c_str(), (const char *)strtok((char *)line.c_str(), ",")) == 1)
            break ;
        i = 0;
        while (line.at(i) != ',')
            i++;
        value = atof(line.substr(i, line.length() - i - 1).c_str());
        if (strcmp(ref.date.c_str(), (const char *)strtok((char *)line.c_str(), ",")) == 0)
            break ;
        line.clear();
    }
    value = atof(ref.nbc.c_str()) * value;
    return (std::to_string(value));
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
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date.at(i) == '-')
        {
            aux.push_back(date.substr(start, i  - 1));
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
    std::cout << "DAY(" << date.dd << ") MONTH(" << date.mm << ") YEAR(" << date.yy << ")" << std::endl;
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
