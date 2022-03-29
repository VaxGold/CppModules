/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:04:40 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 15:49:33 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

typedef struct	Data
{
	int a;
}				Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) 
{
	return (reinterpret_cast<Data *>(raw));
}

int main (void)
{
	Data data; 
	Data *data_b;

	data.a=42;
	uintptr_t _serialize = serialize(&data);
	data_b = deserialize(_serialize);
	std::cout << data_b->a << std::endl;
	std::cout << data_b << std::endl;
	std::cout << &data << std::endl;
	
	return (0);
}
