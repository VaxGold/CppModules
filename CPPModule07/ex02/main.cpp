/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:29 by omercade          #+#    #+#             */
/*   Updated: 2022/03/30 16:27:05 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// class Awesome 
// {
// public: 
// 	Awesome( void ) : _n( 42 ) { return; } 
// 	int get( void ) const { return this->_n; } 
// private: 
// 	int _n; 
// }; 

// std::ostream &operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; } 

// int     main()
// {
//     Array<Awesome> complexType(20);
    
//     for (size_t i = 0; i < 20; i++)
//         std::cout << "Array[" << i << "]---> " << complexType[i] << std::endl;

//     std::cout << "Test#1" << std::endl;
//     try
//     {
//         std::cout << complexType[20] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     std::cout << "Test#2" << std::endl;
//     try
//     {
//         Array<Awesome> test;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
//     std::cout << "Test#3" << std::endl;
//     try
//     {
//         Array<Awesome> test;
//         std::cout << test[0] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

// }
