/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:12:01 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 13:05:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			std::vector<int> testVector;
			testVector.push_back(21);
			testVector.push_back(42);
			testVector.push_back(6323);
			testVector.push_back(2);
			testVector.push_back(89);
			testVector.push_back(216835);
			testVector.push_back(2134);

			std::cout << "# Vector # ----> ";
			try 
			{
				std::vector<int>::iterator iVector = easyFind(testVector, static_cast <int> (stoi(static_cast<std::string> (argv[1]))));
				std::cout << *iVector << std::endl;
			}
			catch( std::invalid_argument& )
			{
				std::cerr << "Invalid string to search in vector <int>" << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::list<int> testList;
			testList.push_back(2372384);
			testList.push_back(42);
			testList.push_back(1);
			testList.push_back(89);
			
			std::cout << "# List # ----> ";
			try 
			{
				std::list<int>::iterator iterL = easyFind(testList, static_cast <int> (stoi(static_cast<std::string> (argv[1]))));
				std::cout << *iterL << std::endl;
			}
			catch(std::invalid_argument&)
			{
				std::cerr << "Invalid string to search in list <int>" << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
    else
        std::cout << "Wrong number of argumments." << std::endl;
	return (0);
}
