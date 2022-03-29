/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:02:43 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 19:32:08 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
 #define ARRAY_HPP
 
# include <iostream>
# include <exception>

template <typename T>

class Array
{
	private:
		T *_data;
		size_t _size;
	public:
		Array() : _data(new T[0]()), _size(0) 
        {
        };
		Array(unsigned int n) : _data(new T[n]()), _size(n)
        {
        };
		Array(const Array<T> & other)
		{
			*this = other;
		};
        virtual	~Array()
		{
			delete [] this->_data;
		};
		Array & operator = (Array const & other)
		{
			if (this == other)
				return *this;
			this->_data = new T[other.getSize()]();
			this->_size = other.getSize();
			for (size_t i = 0; i < other.getSize(); i++)
				this->_data[i] = other._data[i];
			return *this;
		};

		T &operator [] (unsigned int n)
		{
			if (n > static_cast< unsigned int >(this->_size) - 1 || this->getSize() == 0)
				throw ArrayGlobalException();
			return (this->_data[n]);
		};

		size_t getSize () const
		{
			return (this->_size);
		};

		class ArrayGlobalException : public std::exception 
		{
			public:
				virtual const char * what() const throw () 
				{
					return "Error: arrar: ArrayGlobalException";
				};
		};
 

};

#endif
