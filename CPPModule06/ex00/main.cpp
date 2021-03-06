/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omercade <omercade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:41:51 by omercade          #+#    #+#             */
/*   Updated: 2022/03/29 13:37:16 by omercade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main (int argc, char *argv[]) 
{
	if ( argc == 2)
	{
		ScalarConversion example(argv[1]);
		example.showConversions();
	}
	else
		std::cout << "Error : wrong number of arguments" << std::endl;
	return 0;
}