/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:04 by omercade          #+#    #+#             */
/*   Updated: 2022/03/30 14:14:40 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome 
{
public: 
	Awesome( void ) : _n( 42 ) { return; } 
	int get( void ) const { return this->_n; } 
private: 
	int _n; 
}; 

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; } 

template< typename T > 

void	print( T const & x ) { std::cout << x << std::endl; return; }

int main()
{ 
int			tab[] = { 0, 1, 2, 3, 4 };
Awesome 	tab2[5]; 
char		tab3[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
std::string	avengers[] = {"Hulk", "Cpt. America", "Iron man", "Hawkeye", "Blackwidow", "Thor", "Black Panther"};

std::cout << "-----> Test with int <-----" << std::endl;
iter( tab, 5, print ); 
std::cout << "\n-----> Test with class Awesome <-----" << std::endl;
iter( tab2, 5, print );
std::cout << "\n-----> Test with string <-----" << std::endl;
iter( avengers, 7, print );
std::cout << "\n-----> Test with char <-----" << std::endl;
iter( tab3, 10, print );
return 0;
}