/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:40:32 by omercade          #+#    #+#             */
/*   Updated: 2023/05/08 20:35:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ----> BITCOINEXCHANGE CLASS <---- */

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
				str = "Error: invalid date => " + tmp.date;
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
		else
			this->_data.push("Error: bad input => " + line);
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
	Dates mydate(ref.date);
	float value = 0;

	std::getline(file, line);	//Ignore first line of .csv
	while (std::getline(file, line))
	{
		size_t i = 0;
		while (line.at(i) != ',')
			i++;
		std::string str = line.substr(0,i);
		Dates tmp(str);
		if (mydate < tmp)
			break;
		value = atof(line.substr(i + 1, line.length() - i - 1).c_str());
		if (mydate == tmp)
			break;
		line.clear();
	}
	value = atof(ref.nbc.c_str()) * value;
	return (std::to_string(value));
}

int BitcoinExchange::is_validDate(std::string date)
{
	Dates calendar(date);

	/* YEAR CHECK */
	if (calendar.getYear() < 0)
		return (0);
	
	/* MONTH CHECK */
	if (calendar.getMonth() < 1 || calendar.getMonth() > 12)
		return (0);

	/* DAY CHECK */
	if (calendar.getDay() < 1 || calendar.getDay() > 31)
		return (0);
	if (calendar.getMonth() == 2)
	{
		if (calendar.getYear() % 4 == 0 || (calendar.getYear() % 100 == 0 && calendar.getYear() % 400 == 0))
		{
			if (calendar.getDay() > 29)
				return (0);
		}
		else
		{
			if (calendar.getDay() > 28)
				return (0);
		}
	}
	else if ((calendar.getMonth() <= 7 && calendar.getMonth() % 2 == 0) || (calendar.getMonth() >= 8 && calendar.getMonth() % 2 == 1))
	{
		if (calendar.getDay() > 30)
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

	while (line.at(i) != ' ')
	{
		if (!isdigit(line.at(i)) && line.at(i) != '-')
			return 0;
		i++;
		if (i >= line.size())
			return 0;
	}
	i++;
	if (i >= line.size() || line.at(i) != '|')
		return 0;
	i++;
	if (i >= line.size() || line.at(i) != ' ')
		return 0;
	i++;
	if (i >= line.size())
		return 0;
	while (i < line.size() && line.at(i) != ' ')
	{
		if (!isdigit(line.at(i)) && (line.at(i) != '.' && line.at(i) != '-'))
			return 0;
		i++;
	}
	while (i < line.size())
	{
		if (line.at(i) != ' ')
			return 0;
		i++;
	}
	return 1;
}

/* ----> DATES CLASS <---- */

Dates::Dates()
{
	this->yy = 0;
	this->mm = 0;
	this->dd = 0;
}

Dates::Dates(std::string str)
{
	this->yy = 0;
	this->mm = 0;
	this->dd = 0;

	int start = 0;
	size_t i = 0;

	while (str.at(i) != '-')
		i++;
	this->yy = atoi(str.substr(start, i - start).c_str());
	start = ++i;
	while (str.at(i) != '-')
		i++;
	this->mm = atoi(str.substr(start, i - start).c_str());
	start = ++i;
	while (i < str.length())
		i++;
	this->dd = atoi(str.substr(start, str.length() - start).c_str());
}

Dates::Dates(Dates const &other)
{
	*this = other;
}

Dates &Dates::operator=(Dates const &other)
{
	if (this != &other)
	{
		this->yy = other.getYear();
		this->mm = other.getMonth();
		this->dd = other.getDay();
	}
	return (*this);
}

Dates::~Dates() {}

bool Dates::operator==(Dates date) const
{
	return (this->yy == date.getYear() && this->mm == date.getMonth() && this->dd == date.getDay());
}

bool Dates::operator!=(Dates date) const
{
	return (!(*this == date));
}

bool Dates::operator<(Dates date) const
{
	if (this->yy == date.getYear())
	{
		if (this->mm == date.getMonth())
			return this->dd < date.getDay();
		else
			return this->mm < date.getMonth();
	}
	else
		return this->yy < date.getYear();
}

bool Dates::operator<=(Dates date) const
{
	if (this->yy == date.getYear())
	{
		if (this->mm == date.getMonth())
			return this->dd <= date.getDay();
		else
			return this->mm < date.getMonth();
	}
	else
		return this->yy < date.getYear();
}

bool Dates::operator>(Dates date) const
{
	if (this->yy == date.getYear())
	{
		if (this->mm == date.getMonth())
			return this->dd > date.getDay();
		else
			return this->mm > date.getMonth();
	}
	else
		return this->yy > date.getYear();
}

bool Dates::operator>=(Dates date) const
{
	if (this->yy == date.getYear())
	{
		if (this->mm == date.getMonth())
			return this->dd >= date.getDay();
		else
			return this->mm > date.getMonth();
	}
	else
		return this->yy > date.getYear();
}

int Dates::getYear() const
{
	return this->yy;
}

int Dates::getMonth() const
{
	return this->mm;
}

int Dates::getDay() const
{
	return this->dd;
}

/* ----> OTHER <---- */

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
