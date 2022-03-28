/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:41:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/28 20:55:26 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main (int argc, char *argv[]) 
{
	if ( argc == 2)
	{
		ScalarConversion _42( static_cast <const std::string> (argv[1]));
		_42.display();
	}
	else
		std::cout << "Bad arguments " << std::endl;
	return 0;
}