/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:12:24 by omercade          #+#    #+#             */
/*   Updated: 2022/03/31 15:08:02 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(): _size(0)
{
}

Span::Span(unsigned int N): _size(N)
{
}

Span::Span(Span const & other)
{
	*this = other;
}

Span::~Span()
{
	this->_container.clear();
}

Span	&Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_container.clear();
		this->_container = other._container;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_container.size() == this->_size)
		throw Span::SpanOverflowExecption();
	this->_container.push_back(number);
}

int		Span::shortestSpan()
{
	int spanLen;

	if (this->_container.size() < 2)
		throw Span::SpanElementsExecption();
	std::vector<int>::iterator start = this->_container.begin();
	std::vector<int>::iterator next = this->_container.begin() + 1;
	spanLen = std::abs(*start - *next);
	start++;
	next++;
	while (next != this->_container.end())
	{
		if (std::abs(*start - *next) < spanLen)
			spanLen = std::abs( *start - *next );
		start++;
		next++;
	}
	return (spanLen);
}

int		Span::longestSpan()
{
	int spanLen;

	if (this->_container.size() < 2)
		throw Span::SpanElementsExecption();
	std::vector<int>::iterator start = this->_container.begin();
	std::vector<int>::iterator next = this->_container.begin() + 1;
	spanLen = std::abs(*start - *next);
	start++;
	next++;
	while (next != this->_container.end())
	{
		if (std::abs(*start - *next) > spanLen)
			spanLen = std::abs(*start - *next);
		start++;
		next++;
	}
	return (spanLen);
}

const char* Span::SpanElementsExecption::what() const throw()
{
	return "SpanElementsExecption: Not enough elements for span.";
}

const char* Span::SpanOverflowExecption::what() const throw()
{
	return "SpanOverflowExecption: Trying to add elements when is full.";
}
