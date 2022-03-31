/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:12:43 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 16:45:18 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	try
	{
		std::cout << "## DEFAULT TEST ##" << std::endl;
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n## OVERFLOW TEST ##" << std::endl;
		Span wp = Span(5);
		wp.addNumber(5);
		wp.addNumber(3);
		wp.addNumber(17);
		wp.addNumber(9);
		wp.addNumber(11);
		wp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n## NOT ENOUGH ELEMENTS TEST ##" << std::endl;
		Span nn = Span(5);
		//nn.addNumber(5);
		
		std::cout << nn.shortestSpan() << std::endl;
		std::cout << nn.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\n## BIG SPAN TEST ##" << std::endl;
		Span 				spanRnd(10000);
		std::vector <int>	aux;
		for( int i = 0; i < 10000 ; i++ )
		{
			aux.push_back(i * i);
		}
		spanRnd.addNumber(aux.begin(), aux.end());

		std::cout << "shortestSpan: " << spanRnd.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << spanRnd.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
