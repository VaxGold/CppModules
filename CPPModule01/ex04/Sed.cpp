/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:24:43 by omercade          #+#    #+#             */
/*   Updated: 2022/03/21 17:16:43 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed()
{
}

Sed::~Sed()
{
}

std::string Sed::insertStr(std::string const &line, std::string const &haystack, std::string const &needle)
{
	std::string str;
	size_t nlen;
	size_t hlen = haystack.length();

	for (size_t i = 0; i < line.length(); i++)
	{
		nlen = 0;
		while (line[i + nlen] == haystack[nlen] && nlen < hlen)
			nlen++;
		if (nlen == hlen)
		{
			str += needle;
			i += (nlen - 1);
		}
		else
			str += line[i];
	}
	return (str);
}

void Sed::replace(std::string const &filename, std::string const &haystack, std::string const &needle)
{
	std::ifstream file;
	std::ofstream output;
	std::string line;

	if (filename.length() == 0)
		std::cout << "Filename is empty." << std::endl;
	else if (haystack.length() == 0)
		std::cout << "String to replace is empty." << std::endl;
	else if (needle.length() == 0)
		std::cout << "Replacement string is empty." << std::endl;
	else
	{
		file.open(filename);
		if (!file.is_open())
		{
			std::cout << "Input File cannot't be opened." << std::endl;
			return ;
		}
		output.open(filename + ".replace", std::ios::trunc);
		if (!output.is_open())
		{
			std::cout << "Output File cannot be opened." << std::endl;
			file.close();
			return ;
		}
		while (std::getline(file, line))
		{
			output << Sed::insertStr(line, haystack, needle);
			if (!file.eof())
				output << '\n';
		}
		file.close();
		output.close();
	}
}
