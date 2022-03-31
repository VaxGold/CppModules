/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:12:31 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 14:54:37 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <iterator>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_container;
	Span();
public:
	Span(unsigned int N);
	Span(Span const & other);
	~Span();
	Span	&operator=(Span const &other);

	void	addNumber(int number);

	int		shortestSpan();
	int		longestSpan();

	template <typename T>
	
	void addNumber(T begin, T end )
	{
		if ((this->_container.size() + std::distance(begin, end)) > this->_size)
			throw SpanOverflowExecption();
		std::copy(begin, end, std::back_inserter(this->_container));
	};

	class SpanElementsExecption : public std::exception
	{
		public:
				virtual const char *what() const throw ();
	};

	class SpanOverflowExecption : public std::exception
	{
		public:
				virtual const char *what() const throw ();
	};

};

#endif
